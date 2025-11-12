#include<bits/stdc++.h>
using namespace std;
int n,f[5005][5005],l[5005],s[5005];
int dfs(int r,int a){
	if(a==1){
		cout<<r<<" "<<a<<" "<<r<<"\n";
		return r;
	}
	if(s[r-1]-s[r-a]<=l[r])return 0;
	int ans=0;
	for(int i=a-1;i<r;i++){
		int d=dfs(i,a-1);
		ans=(ans+d)%998244353;
	}cout<<r<<" "<<a<<" "<<ans<<"\n";
	return ans;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
	}sort(l+1,l+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+l[i];
		cout<<s[i]<<" ";
	}int ans=0;
	cout<<"\n";
	for(int i=1;i<=n;i++){
		ans+=dfs(n,i);	
	}
	cout<<ans;
	return 0;
}
