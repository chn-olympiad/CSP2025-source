#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string a[N],b[N],c[N],d[N];
int len[N],st[N];
int n,q,l,bg,ans;
bool test=1;
int cnt1,cnt2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
		len[i]=a[i].length();
//		cnt1=cnt2=0;
		for(int j=0;j<len[i];++j)
		{
//			if(test&&(a[i][j]!='a'&&a[i][j]!='b'||b[i][j]!='a'&&b[i][j]!='b'))
//			{
//				test=0;
//			}
//			cnt1+=(a[i][j]=='b');
//			cnt2+=(b[i][j]=='b');
			if(a[i][j]!=b[i][j])
			{
				st[i]=j;
			}
		}
//		if(cnt1!=1||cnt2!=1)
//		{
//			test=0;
//		}
		for(int j=0;j<len[i];++j)
		{
			if(a[i][j]!=b[i][j])
			{
				for(int k=j;k<=st[i];++k)
				{
					c[i]+=a[i][k];
					d[i]+=b[i][k];
				}
				st[i]=j;
				break;
			}
		}
//		cout<<c[i]<<" "<<d[i]<<"\n";
	}
	string s,t,ss,tt;
	while(q--)
	{
		ans=0;
		ss=tt="";
		cin>>s>>t;
		if(s.length()!=t.length())
		{
			cout<<"0\n";
			continue;
		}
//		cnt1=cnt2=0;
		l=s.length();
		for(int i=0;i<l;++i)
		{
//			if(test&&(s[i]!='a'&&s[i]!='b'||t[i]!='a'&&t[i]!='b'))
//			{
//				test=0;
//			}
//			cnt1+=(s[i]=='b');
//			cnt2+=(t[i]=='b');
			if(s[i]!=t[i])
			{
				bg=i;
			}
		}
//		if(cnt1!=1||cnt2!=1)
//		{
//			test=0;
//		}
		for(int i=0;i<l;++i)
		{
			if(s[i]!=t[i])
			{
				for(int j=i;j<=bg;++j)
				{
					ss+=s[j];
					tt+=t[j];
				}
				bg=i;
				break;
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(ss!=c[i]||tt!=d[i])
			{
				continue;
			}
			if(bg-st[i]<0)
			{
				continue;
			}
			if(bg+len[i]-st[i]-1>l)
			{
				continue;
			}
//			if(test)
//			{
//				++ans;
//				continue;
//			}
			bool flag=1;
			for(int j=bg-st[i];j<bg;++j)
			{
				if(s[j]!=a[i][j-(bg-st[i])]||t[j]!=b[i][j-(bg-st[i])])
				{
					flag=0;
					break;
				}
			}
			if(flag==0)
			{
				continue;
			}
//			cout<<i<<" "<<bg+len[i]-st[i]-1<<"\n";
			int ll=ss.length();
			for(int j=bg+ll;j<=bg+len[i]-st[i]-1;++j)
			{
				if(s[j]!=a[i][j-(bg-st[i])]||t[j]!=b[i][j-(bg-st[i])])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				++ans;
			}
		}
		cout<<ans<<"\n";
	}
}
