#include <bits/stdc++.h>
using namespace std;
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen
int a[114],n,m,r,rw;
struct z{int r,c;}s[114];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];r=a[1];
	sort(a+1,a+n*m+1,[](int a,int b){return a>b;});
	for(int i=1;i<=n*m;i++) if(a[i]==r) rw=i;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		int w=(i-1)*n+j;
		if(i&1) s[w]={i,j};
		else s[w]={i,m-j+1};
	}
	}cout<<s[rw].r<<" "<<s[rw].c;
}
