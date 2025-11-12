#include<bits/stdc++.h>
using namespace std;
long long k;
int n,ans;
int a[5000010];
int b[5000010];
bool vis[5000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
//	cout<<endl;
//	cout<<(0^2)<<" "<<(2^1)<<" "<<(2^1^0)<<" "<<(2^1^0^3);
	int l=1,r=1;
	for(int i=l;i<=n;i++){
		for(int j=r;j<=n;j++){
			if((b[j]^b[i-1])==k){
							
			//	cout<<b[j]<<" "<<b[i-1]<<"  "<<(b[j]^b[i-1])<<endl;
				ans++;
			//	cout<<i<<" "<<j<<"   "<<endl;
				l=j+1;
				r=j+1;
				break;
			}
		}
	}
//	cout<<endl;
	cout<<ans;
	return 0;
}
