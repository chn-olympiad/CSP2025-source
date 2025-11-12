#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k;
int d[N],a[N],sum[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1];
		for(int j=1;j<=i;j++){
			int p=a[j];
			for(int x=j+1;x<=i;x++){
				p=(p)xor(a[x]);
			}
			if(p==k)d[i]=max(d[i],d[j-1]+1);
		}
	}
	cout<<d[n];
	return 0;
}
