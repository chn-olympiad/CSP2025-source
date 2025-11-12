#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define dep(a,b,c) for(int a=b;a>=c;--a)
const int N = 1007; const int mod = 1e9+7;
int n,q;
string s1[N],s2[N];
string t1,t2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	rep(i,1,n) cin>>s1[i]>>s2[i];
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		int len=t1.size();
		rep(i,1,n)//choose s1[i] s2[i]
		{
			int l=s1[i].size();
			rep(j,0,len-l)
			{
				//j   j+l-1
				rep(k,0,len-1)
				{
					if(j<=k&&k<=j+l-1)
					{
						if(!(t1[k]==s1[i][k-j]&&t2[k]==s2[i][k-j])) break;
					}
					else if(t1[k]!=t2[k]) break;
					if(k==len-1) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
