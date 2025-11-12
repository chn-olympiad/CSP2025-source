#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],f[N];
int n,k,cnt,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=a[i];
	cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=cnt;j<=i;j++){
			if(j!=i) f[j]^=a[i];
			if(f[j]==k){
				ans++,cnt=i+1;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}