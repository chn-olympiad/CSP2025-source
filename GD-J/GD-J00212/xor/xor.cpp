#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int a[maxn],n,k,maxlen;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int l=1;l<n;l++)
		for(int r=l+1;r<=n;r++){
			int num=0;
			bool f=false;
			for(int i=l;i<=r;i++){
				num^=a[i];
				if(num==k){
					maxlen++;
					l=r-1;
					f=true;
					break;
				}
			}
			if(f)break;
		}
	cout<<maxlen;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
	return 0;
}
