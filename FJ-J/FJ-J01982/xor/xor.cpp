#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],ans,k,d[N];
inline void f(int l,int r,int sk)
{
	if(l>=r){
		return;
	}
	bool b=1;
	for(int j=sk;j<=r-l&&b;j++){
		for(int i=l;i<=l+j&&i+j<=r;i++){
			if(int(d[i+j]^d[i-1])==k){
				ans++;
				b=0;
				f(l,i-1,j+1);
				f(i+j+1,r,j);
				break;
			}
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int dl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=int(d[i-1]^a[i]);
		if(a[i]==k){
			f(dl,i-1,1);
			dl=i+1;
			ans++;
		}
	}
	f(dl,n,1);
	cout<<ans;
	return 0;
}
