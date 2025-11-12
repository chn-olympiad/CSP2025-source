#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int maxn=2e5+9;
void read_s(string &s)
{
	char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c>='a'&&c<='z')
	{
		s+=c;
		c=getchar();
	}
}
string s1[maxn],s2[maxn];
string t1[maxn],t2[maxn];
vector<int>nxt1[maxn],nxt2[maxn];
int l[maxn],r[maxn];
int n,q;
bool check_s(string s)
{
	bool flag=false;
	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i]!='a'&&s[i]!='b')return false;
		if(s[i]=='b')
		{
			if(flag)return false;
			flag=true;
		}
	}
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(!check_s(s1[i]))return false;
		if(!check_s(s2[i]))return false;
	}
	for(int i=1;i<=q;i++)
	{
		if(!check_s(t1[i]))return false;
		if(!check_s(t2[i]))return false;
	}
	return true;
}
const int maxl=5e6+9;
int cnt1[maxl],cnt2[maxl];
int pos1[maxn],pos2[maxn];
int ls1[maxn];
bool cmp1(int x,int y)
{
	return ls1[x]<ls1[y];
}
bool cmp2(int x,int y)
{
	return l[x]<l[y];
}
int sum[maxn];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int k=1;k<=n;k++)
	{
		pos1[k]=k;
		read_s(s1[k]);
		s1[k]+='#';
		nxt1[k].resize(s1[k].size()+1);
		//cout<<s1[k]<<endl;
		nxt1[k][0]=-1;
		for(int i=1,j=-1;i<s1[k].size()-1;i++)
		{
			while(j!=-1&&s1[k][i]!=s1[k][j+1])j=nxt1[k][j];
			if(s1[k][i]==s1[k][j+1])j++;
			nxt1[k][i]=j;
		//	printf("[%d %d %d]\n",k,i,nxt1[k][i]);
		}
		read_s(s2[k]);
		s2[k]+='*';	
		nxt2[k].resize(s2[k].size()+1);
		nxt2[k][0]=-1; 
		for(int i=1,j=-1;i<s2[k].size()-1;i++)
		{
			while(j!=-1&&s2[k][i]!=s2[k][j+1])j=nxt2[k][j];
			if(s2[k][i]==s2[k][j+1])j++;
			nxt2[k][i]=j; 
		}	
	}
	for(int k=1;k<=q;k++)
	{
		pos2[k]=k;
		read_s(t1[k]);
		t1[k]+='?';
		
		read_s(t2[k]);
		t2[k]+='!';
		
		for(int i=0;i<t1[k].size();i++)
		{
			if(t1[k][i]!=t2[k][i])
			{
				l[k]=i-1;
				break;
			}
		}
		for(int i=t1[k].size()-2;i>=0;i--)
		{
			if(t1[k][i]!=t2[k][i])
			{
				r[k]=i+1;
				break;
			}
		}
	//	printf("[%d %d]\n",l[k],r[k]);
	}
	if(0)
	{	
		
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<s1[i].size();j++)
			{
				if(s1[i][j]=='b')
				{
					ls1[i]=j-1;
					break;
				}
			}
		}
		sort(pos1+1,pos1+1+n,cmp1);
		sort(pos2+1,pos2+1+q,cmp2);
		for(int i=1,j=0;i<=q;i++)
		{
			while(j+1<=n&&ls1[pos1[j+1]]<=l[pos2[i]])
			{
		
				j++;
				int p1=-1,p2=-1;
				for(int k=0;k<s1[pos1[j]].size()-1;k++)
				{
					if(s1[pos1[j]][k]=='b')p1=k;
					if(s2[pos1[j]][k]=='b')p2=k;
				}
		//		printf("[%d %d %d]\n",j,p1,p2);
				if(p1<p2)
				{
					cnt1[p2-p1]++;
				}
				else
				{
					cnt2[p1-p2]++;
				}
			}
			int p1=-1,p2=-1;
			for(int k=0;k<t1[pos2[i]].size()-1;k++)
			{
				if(t1[pos2[i]][k]=='b')p1=k;
				if(t2[pos2[i]][k]=='b')p2=k;
			}
			if(p1<p2)
			{
				sum[pos2[i]]=cnt1[p2-p1];
			}
			else
			{
				sum[pos2[i]]=cnt2[p1-p2];
			}
		}
		for(int i=1;i<=q;i++)
		{
			printf("%d\n",sum[i]);
		}
		return 0;
	}
//	putchar('\n');
	for(int y=1;y<=q;y++)
	{
		ll ans=0;
		for(int x=1;x<=n;x++)
		{
			if(s1[x].size()>t1[y].size())continue;
			for(int i=0,j1=-1,j2=-1;i<t1[y].size()-1;i++)
			{
				while(j1!=-1&&t1[y][i]!=s1[x][j1+1])
				{
					j1=nxt1[x][j1];
				//	printf("[%d]\n",j1);
				}
				if(s1[x][j1+1]==t1[y][i])j1++;
				
				while(j2!=-1&&t2[y][i]!=s2[x][j2+1])
				{
					j2=nxt2[x][j2];
				}
				if(s2[x][j2+1]==t2[y][i])j2++;
				
				if(j1==s1[x].size()-2&&j2==s2[x].size()-2)
				{
				//	printf("[%d %d]\n",x,i);
				//	cout<<i-int(s1[x].size()-1)<<endl;
					if(i-int(s1[x].size()-1)<=l[y]&&i+1>=r[y])
					{
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

