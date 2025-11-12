#include<bits/stdc++.h>
using namespace std;
int n,sum,maxx=0;
int a[5005];
void dfs(int x){
	if(x>n){
	//	cout<<sum<<" ";
		maxx=max(maxx,sum)/10;
		return ;
	}
//	int now=a[x];
	for(int i=x;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))){
					sum++; 
				} 
			}
		}
	}
	dfs(x+1);
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	cout<<maxx;
	return 0;
}
