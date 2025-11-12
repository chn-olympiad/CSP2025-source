#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005];
int f[500005];
int mx=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int res=0;
		f[i]=max(f[i],mx);
		for(int j=i;j>=1;j--){
			if(j==i) res=a[j];
			else res^=a[j];
			if(f[j]<mx) break;
			if(res==k){
				f[i]=max(f[i],f[j-1]+1);
			}
			if(f[i]>mx) break;
		}
		mx=max(f[i],mx);
	}
	cout<<f[n];
	return 0;
} 
