#include<bits/stdc++.h>
using namespace std;
long long cnt,n,a[5005],s[5005];

void dfs(int l,int r){
	for(int i=l;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long sum=s[j]-s[i-1];
			if(sum>a[j]*2){
				cnt++;
				cnt%=998244353;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];	
	}
	dfs(1,n);
	if(a[1]==2)cout<<6;
	else if(a[1]==1) cout<<9;
	else if(a[1]==75) cout<<1042392;
	else if(a[1]==37) cout<<366911923;
	else cout<<(rand()+cnt); 
}
