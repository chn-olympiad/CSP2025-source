#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,ans;
ll a[500005],b[500005];
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((b[i]^b[j-1])==k){
				bool flog=1;
				for(int k=j;k<=i;k++){
					if(vis[k]){
						flog=0;
					}
				}
				if(flog==1){
					vis[i]=1;
					vis[j]=1;
					ans+=flog;	
				}
				
			}
			
		}
		
	}
	cout<<ans;
	return 0;
} 


