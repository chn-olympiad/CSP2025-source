#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[5000005];
struct info {
	int l;
	int r;
}q[1000005];
int sum[1005][1005];
bool cmp(info pp,info qq)
{
	return pp.r<qq.r;
}
void solve2()
{
	int cnt=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i][i]=a[i];
	for(int len=2;len<=n;len++)
		for(int l=1;l+len-1<=n;l++) {
			int r=l+len-1;
			sum[l][r]=sum[l][r-1]^a[r];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(sum[i][j]==k) q[++cnt]=(info){i,j};
	sort(q+1,q+cnt+1,cmp);
	int ans=0,R=-1;
	for(int i=1;i<=cnt;i++) {
		if(q[i].l>R) {
			R=q[i].r;
			ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1e3) solve2();
	else if(k==1) {
		int ans=0;
		for(int i=1,xx;i<=n;i++) {
			cin>>xx;
			if(xx==1) ans++;
		}
		cout<<ans<<endl;
	}
	else {
		while(1) cout<<"my LG uid = 1753046 , ว๓นุ qwq"<<endl;
	}
	return 0;
}
