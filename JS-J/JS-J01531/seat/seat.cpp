#include <bits/stdc++.h>
using namespace std;

int n,m,cnt;
int a[15][15];
struct stu{
	int sco;
	int op;
	bool operator<(const stu& k) const
	{
		return sco>k.sco;
	}
}t[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;++i)
		t[i].op=i,cin>>t[i].sco;
	sort(t+1,t+n*m+1);
	for (int i=1;i<=m;++i){
		if (i&1)
			for (int j=1;j<=n;++j)
				a[i][j]=t[++cnt].op;
		else
			for (int j=n;j>=1;--j)
				a[i][j]=t[++cnt].op;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			if (a[i][j]==1){
				cout<<i<<' '<<j;
				return 0;
			}
	return 0;
}

