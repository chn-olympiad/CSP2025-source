#include<bits/stdc++.h>
using namespace std;
long long a[1000005],ans=0,n,k;
long long s[1000005];
void dfs(long long l,long long r,long long p){
	if(r>n){
		ans=max(ans,p);
		return ;
	}
	if((s[r]^s[l-1])==k){
		dfs(r+1,r+1,p+1);
		return ;
	}
	if(l==r) dfs(l,r+1,p);
	else{
		dfs(l+1,r,p);
		dfs(l,r+1,p);
	}
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long u1=0;
	long long u2=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) u1=1;
		if(a[i]!=0&&a[i]!=1) u2=1;
		s[i]=s[i-1]^a[i];
	}
	if(u1==0&&k==0){
		cout<<n/2;
		return 0;
	}
	if(u2==0&&k<=1){
		if(k==0){
			for(long long i=1;i<=n;i++){
				if(a[i]==0)
					ans++;
				else{
					if(i<n&&a[i+1]!=1){
						ans++;
						i++;
					}
				}
			}
		}
		else{
			for(long long i=1;i<=n;i++)
				ans+=a[i];
		}
		cout<<ans;
		return 0;
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
