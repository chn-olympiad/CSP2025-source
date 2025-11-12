#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans,a[27],o,k;
string s[N],ss[N],t,tt,c,x,y,z,op,oq;
int check(string uv,string uy)
{
	int p=0;
	for(int i=1;i<=n;i++)
		if(s[i]==uv&&uy==ss[i]) p++;
	return p;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>ss[i],a[s[i][0]-'a']=1;
	while(q--)
	{
		ans=0,o=0,k=0;
		cin>>t>>tt;
		int l=t.size();
		if(t.size()!=tt.size()) cout<<ans<<'\n';
		else{
			if(t[0]!=tt[0])
			{
				c=t[0],y=tt[0];
				if(!a[t[0]-'a'])
					cout<<ans<<'\n';
				else
				{
					for(int i=l-1;i>=0;i--)
						if(t[i]==tt[i]) o++;
						else break;
					for(int i=1;i<n-o-1;i++) c+=t[i],y+=tt[i];
					for(int i=n-o-1;i<n;i++)
					{
						c+=t[i],y+=tt[i];
						ans+=check(c,y);
					} 
					cout<<ans<<'\n';
				}
			}
			else
			{
				k=1;
				for(int i=1;i<l;i++)
					if(t[i]==tt[i]) k++;
					else break;
				for(int i=l-1;i>=0;i--)
					if(t[i]==tt[i]) o++;
					else break;
				c=t[k],y=tt[k];
				for(int i=k+1;i<l-o;i++)
					c+=t[i],y+=tt[i];
				ans+=check(c,y);
				for(int i=k-1;i>=0;i--)
				{
					if(a[c[0]-'a'])
					for(int j=l-o;j<l;j++)
					{
						z+=t[j];
						op=c+z;
						oq=y+z;
						ans+=check(op,oq);
					}
					z.clear();
					c=t[i]+c;
					y=tt[i]+y;
					ans+=check(c,y);
				}
				if(a[c[0]-'a'])
				for(int j=l-o;j<l;j++)
				{
					z+=t[j];
					op=c+z;
					oq=y+z;
					ans+=check(op,oq);
				}
				z.clear();
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}

