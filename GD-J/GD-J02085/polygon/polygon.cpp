#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n;
long long num=0;
void dfs(int bian,int yz,int id){
	if(yz==bian){
		if(bian==3){
			if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1])num++;
		}else num++;
		num%=998244353;
		return;
	}
	for(int i=id;i<=n;i++){
		dfs(bian,yz+1,i+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(i,0,1);
	}
	cout<<num;
	return 0;
} 
