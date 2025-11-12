#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 2e5 + 10;
int n,q;
string S[N][2],t1,t2,tmp[2];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int a=1;a<=n;a++)
		cin>>S[a][0]>>S[a][1];
	for(int subject=1;subject<=q;subject++)
	{
		cin>>t1>>t2;
		int ans = 0;
		for(int l=-1;l<t1.size();l++)
			for(int r=l+1;r<=t1.size();r++)
			{
				bool vis = 0;
				for(int i=0;i<=l;i++)
					if(t1[i] != t2[i]){vis = 1;break;}
				if(vis) continue;
				for(int i=r;i<t1.size();i++)
					if(t1[i] != t2[i]){vis = 1;break;}
				if(vis) continue;
				tmp[0] = "",tmp[1] = "";
				for(int i=l+1;i<=r-1;i++) tmp[0] += t1[i],tmp[1] += t2[i];
				for(int i=1;i<=n;i++)
					if(S[i][0] == tmp[0] && S[i][1] == tmp[1])
						ans ++;
			}
		cout<<ans<<"\n";
	}
	return 0;
}