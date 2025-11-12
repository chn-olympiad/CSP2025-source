#include<bits/stdc++.h>
using namespace std;
long long a[10000001],b[1001][1001],vis[10000001];
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.out","r",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			for(long long k=i;k<=j;k++){
				b[i][j]^=a[k];
			}
			if(b[i][j]==k && vis[i]==0 && vis[j]==0){
				for(long long k=i;k<=j;k++) vis[k]=1;
				ans++;
			} 
		}
		
	}
	cout<<ans;
	return 0;
}
