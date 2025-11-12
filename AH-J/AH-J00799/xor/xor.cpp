#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long kk=0;
void dfs(long long u,long long sum,long long s){
	if(u>n){
		if(kk<s){
			kk=s;
		}
		return;
	}
	if((a[u]^sum)==k)dfs(u+1,0,s+1);
	else{
		dfs(u+1,a[u]^sum,s);
		dfs(u+1,0,s);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k<=1){
		long long sum=-1;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(sum==-1){
				if(a[i]==k){
					ans++;
				}	
				else sum=a[i];
			}
			else{
				if((a[i]^sum)==k){
					ans++;
					sum=-1;
				}
				else{
					sum^=a[i];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		dfs(1,0,0);
		cout<<kk;
	}
	return 0;
}
