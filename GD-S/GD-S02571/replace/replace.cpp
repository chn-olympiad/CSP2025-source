#include<bits/stdc++.h>
using namespace std;
long long n,q,c[200005],wz[200005][2],m,w1,w2,an,ky;
string s[200005][2],t1,t2,bt[200005][2],zs1,zs2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		w1=w2=0;
		c[i]=s[i][0].size();
		s[i][0]=" "+s[i][0];
		s[i][1]=" "+s[i][1];
		for(int j=1;j<=c[i];j++)
		{
			if(s[i][0][j]!=s[i][1][j])
			{
				w1=j;
				break;
			}
		}
		for(int j=c[i];j>=1;j--)
		{
			if(s[i][0][j]!=s[i][1][j])
			{
				w2=j;
				break;
			}
		}
		wz[i][0]=w1;
		wz[i][1]=w2;
		bt[i][0]="";
		bt[i][1]="";
		for(int j=w1;j<=w2;j++)
		{
			bt[i][0]+=s[i][0][j];
			bt[i][1]+=s[i][1][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		an=0;
		cin>>t1>>t2;
		m=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		for(int j=1;j<=m;j++)
		{
			if(t1[j]!=t2[j])
			{
				w1=j;
				break;
			}
		}
		for(int j=m;j>=1;j--)
		{
			if(t1[j]!=t2[j])
			{
				w2=j;
				break;
			}
		}
		zs1="";
		zs2="";
		for(int j=w1;j<=w2;j++)
		{
			zs1+=t1[j];
			zs2+=t2[j];
		}
		for(int j=1;j<=n;j++)
		{
			if(zs1==bt[j][0]&&zs2==bt[j][1])
			{
				ky=1;
				for(int k=w1-1,kk=wz[j][0]-1;kk>=1;k--,kk--)
				{
					if(t1[k]!=s[j][0][kk])
					{
						ky=0;
						break;
					}
				}
				for(int k=w2+1,kk=wz[j][1]+1;kk<=c[j];k++,kk++)
				{
					if(t1[k]!=s[j][0][kk])
					{
						ky=0;
						break;
					}
				}
				an+=ky;
			}
		}
		cout<<an<<'\n';
	}
	return 0;
}
