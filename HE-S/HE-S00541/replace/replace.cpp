#include<bits/stdc++.h>
using namespace std;
int n,q,l;
string s1,s2;
char p1[5000001],p2[5000001];
struct dui
{
	string s1,s2;
	int l;
}a[100001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s1>>a[i].s2;
		a[i].l=a[i].s1.length();
	}
	while(q--)
	{
		cin>>s1>>s2;
		l=s1.length();
		int h=0;
		for(int i=0;i<l;i++)
		{
			if(s1[i]!=s2[i])
			{
				p1[h]=s1[i];
				p2[h]=s2[i];
				h++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].l==l)
			{
				int f=1;
				for(int j=0;j<l;j++)
				{
					if(p1[j]!=a[i].s1[j]||p2[j]!=a[i].s2[j])
					{
						f=0;
					}
				}
				if(f==1)
				{
					cout<<i;
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
