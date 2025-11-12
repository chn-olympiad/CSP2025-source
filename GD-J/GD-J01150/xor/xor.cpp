#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2<<20,M=5e5+5;
int n,k,ans,id;
int a[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		int p=0;
		for(int j=i;j>id;--j){
			p^=a[j];
			if(p==k){
				id=i;
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//4 2
//2 1 0 3

