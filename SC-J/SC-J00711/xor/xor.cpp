#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int maxn=5e5+8;
int n,k;
int a[maxn];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1,ans=0,cnt=0;
	while(r<=n){
		ans^=a[r];
		r++;
		if(ans==k){
			cnt++;
			l=r;
			ans=0;
		}
	}
	cout<<cnt;

	return 0;
}