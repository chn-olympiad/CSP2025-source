#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ans=0,last=0;
long long k,a[N];
map <long long,int> v;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n; cin>>n>>k;
	long long p=0,q=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=0;
	for(int i=1;i<=n;i++) {
	    p^=a[i-1];
	    v[p^k]=i;
	    q^=a[i];
	    if(v[q]!=0&&v[q]>last) last=i,ans++;
	}
	cout<<ans;
    return 0;	
}
