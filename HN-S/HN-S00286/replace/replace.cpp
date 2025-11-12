#include<bits/stdc++.h>
using namespace std;
//unsigned long long a[200002],b[200002],A[5000002],B,aa[50000002];
int n,m,p;
bool d,e=true;
string q[200002],r[200002],s[200002],t[200002];
//void E(string C,int D)
//{
//	for(int i=0;i<C.length();i++)
//	{
//		a[D]=a[D]*293+C[i];
//	}
//	return;
//}
//void F(string C,int D)
//{
//	for(int i=0;i<C.length();i++)
//	{
//		b[D]=b[D]*293+C[i];
//	}
//	return;
//}
//void S(string C)
//{
//	A[C.length()]=0;
//	for(int i=1;i<C.length();i++)
//	{
//		A[i]=A[i]*293+C[i];
//	}
//	return;
//}
//void R(string C)
//{
//	for(int i=1;i<C.length();i++)
//	{
//		B=B*293+C[i];
//	}
//	return;
//}
//unsigned long long T(int p,int q,unsigned long long r)
//{
//	return a[p-1]+a[k]-a[p+q+1]+r*aa[p];
//}
//unsigned long long K(int p,int q)
//{
//	return a[p+q]-a[p-1];
//}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	for(int i=0;i<5000001;i++)
//	{
//		aa[i]=aa[i-1]*293;
//	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i]>>r[i];
//		E(q,i);
//		F(r,i);
		if(e)
		{
			d=false;
			for(int j=0;j<q[i].length();j++)
			{
				if((q[i][j]>'b')||((q[i][j]=='b')&&d))
				{
					e=false;
					break;
				}
				d|=(q[i][j]=='b');
			}
			d=false;
			for(int j=0;j<r[i].length();j++)
			{
				if((r[i][j]>'b')||((r[i][j]=='b')&&d))
				{
					e=false;
					break;
				}
				d|=(r[i][j]=='b');
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s[i]>>t[i];
//		s[i]='#'+s[i];
//		t[i]='#'+t[i];
		if(e)
		{
			if(s[i].length()!=t[i].length())
			{
				continue;
			}
			d=false;
			for(int j=0;j<s[i].length();j++)
			{
				if((s[i][j]>'b')||((s[i][j]=='b')&&d))
				{
					e=false;
					break;
				}
				d|=(s[i][j]=='b');
			}
			d=false;
			for(int j=0;j<t[i].length();j++)
			{
				if((t[i][j]>'b')||((t[i][j]=='b')&&d))
				{
					e=false;
					break;
				}
				d|=(t[i][j]=='b');
			}
		}
	}
	if(e)
	{
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		if(s[i].length()!=t[i].length())
		{
			cout<<"0\n";
			continue;
		}
		p=0;
//		S(s[i]);
//		R(t[i]);
//		k=s[i].length()-1;
		for(int k=1;k<=n;k++)
		{
			for(int j=0;j+q[k].length()<s[i].length();j++)
			{
				p+=(s[i].substr(0,j)+q[k]+s[i].substr(j+q[k].length())==t[i]);
			}
		}
		cout<<p<<endl;
	}
	return 0;
}
