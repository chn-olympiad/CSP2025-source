#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int al, bl, cl, i, n, A, B, C, M, ans, a[N], b[N], c[N];
void solve(){
	ans=al=bl=cl=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&A,&B,&C);
		M=max(A, max(B, C));
		ans+=M;
		if(M==A)a[++al]=M-max(B, C);
		if(M==B)b[++bl]=M-max(A, C);
		if(M==C)c[++cl]=M-max(B, C);
	}
	sort(a+1, a+al+1);
	sort(b+1, b+bl+1);
	sort(c+1, c+cl+1);
	if(al>n/2)for(i=al-n/2;i;i--)ans-=a[i];
	if(bl>n/2)for(i=bl-n/2;i;i--)ans-=b[i];
	if(cl>n/2)for(i=cl-n/2;i;i--)ans-=c[i];
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;while(T--)solve();
	return 0;
}
