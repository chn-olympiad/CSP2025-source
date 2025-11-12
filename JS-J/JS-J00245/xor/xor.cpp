#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],c[N];
bool vis[N];
long long k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,ans=0;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1]^a[i];
		if(a[i]==k){
			ans++;
			vis[i]=true;
		}
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]==true){
			continue;
		}
		for(long long j=i+1;j<=n&&vis[j]==false;j++){
			if((c[j]^c[i-1])==k){
				ans++;
				for(long long k=1;k<=j;k++){
					vis[k]=true;
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}	
