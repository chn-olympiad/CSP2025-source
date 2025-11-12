#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,k;
int a[500005];
int s[500005];
int ans=1;
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];		
	}
	for(int i=1;i<=n;i++){
		mp[s[i-1]^k]=ans;
		if(mp[s[i]]==ans){
			ans++;
		}
	}
	cout<<ans-1<<'\n';
	return 0;
}       
