#include <bits/stdc++.h>
using namespace std;
using unint=unsigned int;

unint n,k,ans,i,l,r,flag,len;
unint a[500005];
bitset<500005> f;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (i=1;i<=n;++i)
		cin>>a[i],a[i]^=a[i-1];
	for (len=0;len<n;++len){
		for (l=1;l<=n-len;++l){
			r=l+len,flag=0;
			for (i=r;i>=l;--i)
				if (f[i]){
					flag=i;
					break;
				}
			if (flag){
				l=flag;
				continue;
			}
			if ((a[r]^a[l-1])==k){
				++ans;
				f[l]=1;
				f[r]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/
