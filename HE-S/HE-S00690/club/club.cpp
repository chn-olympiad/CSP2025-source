#include <bits/stdc++.h>
using namespace std;
int t;
int n;
const int MAXN=1e5+5;
int a[MAXN][5];
int b[MAXN];

bool cmp(int a,int b) {return a>b;}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		int fen=n/2;
        for(int i=1;i<=n;i++) b[i]=a[i][1];
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=fen;i++) ans+=b[i];
		cout<<ans<<"\n";
		memset(a,'0',sizeof(a));
		memset(b,'0',sizeof(b));
	}
	return 0;
}
