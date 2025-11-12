#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5,MAXN2=2e6+5;//2^20=272144<500001
int a[MAXN];
int xora[MAXN],s[MAXN],t[MAXN2];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	t[0]=0;
	for(int i=1; i<=MAXN2; i++) {
		t[i]=-1;
	}
	xora[0]=0;
	s[0]=0;
	for(int i=1; i<=n; i++) {
		xora[i]=xora[i-1]^a[i];
		s[i]=s[i-1];
		int u=xora[i]^k;
		if(t[u]!=-1) {
			s[i]=max(s[i],s[t[u]]+1);
		}
		if(t[xora[i]]=i) {
			t[xora[i]]=i;
		}
	}
	cout<<s[n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}