#include<bits/stdc++.h>
#define int long long
using namespace std;

string st[100005][5];

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>st[i][1]>>st[i][2];
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int pos=0;
			while(pos<int(x.length()))
			{
				int lin=x.find(st[j][1],pos);
				if(!(lin>=0&&lin<int(x.length()))) break;
				for(int i=0;i<lin;i++) if(x[i]!=y[i]) goto end;
				for(int i=lin;i<=lin+int(st[j][1].length())-1;i++) if(st[j][2][i-lin]!=y[i]) goto end;
				for(int i=lin+int(st[j][1].length());i<int(x.length());i++) if(x[i]!=y[i]) goto end;
				ans++;
			//end1: break;
			end: ;
			}
		}
		cout<<ans<<"\n";
	}
}
