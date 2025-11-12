#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define maxn 6000005
ll n,m,t,ans=0,op[maxn],mlen=-INF;
string a[maxn],b[maxn],c,d;
map<string,string> e;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		if(a[i].length()==b[i].length())
		{
			e[a[i]]=b[i];
			mlen=max(mlen,(ll)a[i].length());
		}
	}
	while(m--)
	{
		cin>>c>>d;
		memset(op,0,sizeof(op));
		if(c.length()!=d.length())
		{
			cout<<0<<'\n';
			continue;
		}
		int start=-1,end=-1;
		for(int i=0;i<c.length();i++)
		{
			if(c[i]!=d[i])
			{
				if(start==-1)start=i;
				op[i]=1;
				end=i;
			}
		}
		string g="",h="";
		int ans=0;
		for(int i=start;i<=end;i++)g+=c[i],h+=d[i];
		if(e[g]==h)ans++;
		int l=start,r=end;
		while(l>0||r<c.length()-1)
		{
			string x1,x2,x3;
			string z1,z2,z3;
			x1=c[l-1]+g;
			x2=g+c[r+1];
			x3=c[l-1]+g+c[r+1];
			z1=d[l-1]+h;
			z2=g+d[r+1];
			z3=d[l-1]+h+d[r+1];//cout<<z3<<'\n';
			if(e[x1]==z1)ans++;
			if(e[x1]==z2)ans++;
			if(e[x2]==z1)ans++;
			if(e[x2]==z2)ans++;
			if(e[x3]==z3)ans++;
			if(l!=0)l--,g=c[l]+g,h=d[l]+h;
			if(r!=c.length()-1)r++,g=g+c[r],h=h+d[r];
			
			if(l==0&&r==r!=c.length()-1)break;
		}
		//cout<<l<<' '<<r<<' ';
		cout<<ans<<'\n';
	}
	return 0;
}
