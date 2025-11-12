#include <iostream>
#define N 500005
using namespace std;

int n,k,ans;
int a[N],s[N];
long long v[N],vv[N],c[N];//a:原 s:抑或前缀 vv:访问原 v:访问前缀 c:差分 

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int l=1; l<=n; l++) {
		for(int i=1; i<=n; i++) c[i]=vv[i]-vv[i-1];
		for(int i=1; i+l-1<=n; i++) {
			int j=i+l-1;
			if(v[j]-v[i-1]) continue;
			if((s[j]^s[i-1])==k) c[i]++,c[j+1]--,ans++;
		}
		for(int i=1; i<=n; i++) vv[i]=vv[i-1]+c[i];
		for(int i=1; i<=n; i++) v[i]=v[i-1]+vv[i];
	}
	cout<<ans;
	return 0;
}
