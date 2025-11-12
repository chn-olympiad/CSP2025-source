#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e3;
int n,q,ans,len[N];
string x,y,a[N],b[N],s[N][2];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],len[i]=s[i][0].size();
	while(q--)
	{
		ans=0;
		cin>>x>>y; 
		int lenx=x.size(),leny=y.size();
		x=" "+x; y=" "+y;
		a[0]=" "; b[lenx+1]="";
		for(int i=1;i<=lenx;i++) a[i]=a[i-1]+x[i];
		for(int i=lenx;i;i--) b[i]=x[i]+b[i+1];
		for(int i=1;i<=n;i++)
		{
			int p=x.find(s[i][0],1);
			while(p>=1)
			{
				if(a[p-1]+s[i][1]+b[p+len[i]]==y) ans++;
				p=x.find(s[i][0],p+1);
			}
		}
		cout<<ans<<"\n";
	}
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb

//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a