#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
const int maxn=2e5+5;
string a[maxn][3],t[maxn][3],taq[maxn][3],k[maxn];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
		taq[i][1]=a[i][1];
		taq[i][2]=a[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	int s,e;
	for(int j=1;j<=n;j++)
	{
		s1=a[j][1],s2=a[j][2];
		int op=s1.size();
		if(s1!=s2)
		{
		for(int i=0;i<op;i++)
		{
			if(s1[i]!=s2[i])
			{
				s=i;
				break;
			}
		}
		for(int i=op-1;i>=0;i--)
		{
			if(s1[i]!=s2[i])
			{
				e=i;
				break;
			}
		}
		a[j][1]="";
		a[j][2]="";
		for(int i=s;i<=e;i++)
		{
			a[j][1]+=s1[i];
		}
		for(int i=s;i<=e;i++)
		{
			a[j][2]+=s2[i];
		}
	}
	}
	for(int j=1;j<=q;j++)
	{
		s1=t[j][1],s2=t[j][2];
		int op=s1.size();
		if(s1!=s2)
		{
		for(int i=0;i<op;i++)
		{
			if(s1[i]!=s2[i])
			{
				s=i;
				break;
			}
		}
		for(int i=op-1;i>=0;i--)
		{
			if(s1[i]!=s2[i])
			{
				e=i;
				break;
			}
		}
		t[j][1]="";
		t[j][2]="";
		for(int i=s;i<=e;i++)
		{
			t[j][1]+=s1[i];
		}
		for(int i=s;i<=e;i++)
		{
			t[j][2]+=s2[i];
		}
	}
	}
	int ans;
	bool flag;
	for(int i=1;i<=q;i++)
	{
		ans=0;
		string s1=t[i][1],s2=t[i][2];
		for(int j=1;j<=n;j++)
		{
			if(a[j][1]==s1&&a[j][2]==s2)
			{
				flag=true;
				for(int p=0;p<ans;p++)
				{
					if(taq[j][1]+taq[j][2]==k[p])
					{
						flag=false;
						break;
					}
				}
				if(flag==true)
				{
					k[ans]=taq[j][1]+taq[j][2];
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
