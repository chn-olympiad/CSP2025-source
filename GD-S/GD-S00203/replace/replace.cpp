# include <cstdio>
# include <cstring>
# include <algorithm>
# include <random>
# define int long long
using namespace std;
const unsigned int m1=998244353,m2=1000000007,m3=13333331;
int n,Q,sum,cnt,d[5000007];
char s1[5000007],s2[5000007];
unsigned int mi[5000007],h1[5000007],h2[5000007],s[5000007][3];
std::mt19937 rnd(0);
void qsort(int x,int y)
{
	int i=x,j=y;
	unsigned mid=s[rnd()%(y-x+1)+x][1];
	while(i<=j)
	{
		while(s[i][1]<mid) i++;
		while(s[j][1]>mid) j--;
		if(i<=j)
		{
			swap(s[i],s[j]);
			i++,j--;
		}
	}
	if(i<y) qsort(i,y);
	if(x<j) qsort(x,j);
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	mi[0]=1;
	for(int i=1;i<=5000000;i++) mi[i]=mi[i-1]*29;
	scanf("%lld%lld",&n,&Q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s1,s2);
		int n1=strlen(s1);
		int x1=-1;
		for(int i=0;i<n1;i++)
		{
			if(s1[i]!=s2[i]) x1=i;
		}
		if(x1==-1) continue;
		unsigned int ans1=0,ans2=0;
		for(int i=0;i<=x1;i++) ans1=ans1*29+s1[i]-'a'+1,ans2=ans2*29+s2[i]-'a'+1;
		unsigned int ans3=0;
		for(int i=x1+1;i<n1;i++) ans3=ans3*29+s1[i]-'a'+1;
		cnt++;
		s[cnt][0]=ans1*m1+ans2*m2+ans3*m3,s[cnt][1]=x1+1,s[cnt][2]=n1-x1-1;
	}
	qsort(1,cnt);
	for(int mayfly=1;mayfly<=Q;mayfly++)
	{
		scanf("%s%s",s1,s2);
		int n1=strlen(s1),n2=strlen(s2);
		if(n1!=n2)
		{
			printf("0\n");
			continue;
		}
		int x1=-1,x2=n;
		for(int i=0;i<n1;i++)
		{
			if(s1[i]!=s2[i]) x1=i;
		}
		for(int i=n1-1;i>=0;i--)
		{
			if(s1[i]!=s2[i]) x2=i;
		}
		for(int i=0;i<n1;i++)
		{
			if(i==0)
			{
				h1[i]=s1[i]-'a'+1;
				h2[i]=s2[i]-'a'+1;
			}
			else
			{
				h1[i]=h1[i-1]*29+s1[i]-'a'+1;
				h2[i]=h2[i-1]*29+s2[i]-'a'+1;
			}
		}
		sum=0;
		for(int i=cnt;i>=1;i--)
		{
			int qd=s[i][1],hd=s[i][2];
			if(qd<x1-x2+1) break;
			if(hd>n1-x1-1) continue;
			unsigned int ans1=h1[x1]-h1[x1-qd]*mi[qd];
			unsigned int ans2=h2[x1]-h2[x1-qd]*mi[qd];
			unsigned int ans3=h1[x1+hd]-h1[x1]*mi[hd];
			unsigned int ans=ans1*m1+ans2*m2+ans3*m3;
			if(ans!=s[i][0]) continue;
			sum++;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
