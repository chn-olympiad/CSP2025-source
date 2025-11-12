#include<bits/stdc++.h>
using namespace std;
int a[10010],ans,sum,n;
int maxn=INT_MIN,cnt=0;
void f(int g){
	cnt++;
	maxn=max(maxn,a[g]);
	sum+=a[g];
	if(cnt>=3&&maxn*2<sum){
		ans++;
		return ;
	}
	for(int i=g+1;i<=n;i++){
		f(i);
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n-2;i++){
		f(i);
	}
	cout<<ans%998244353;
	return 0;
} 
