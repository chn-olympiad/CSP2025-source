#include<bits/stdc++.h>
using namespace std;
const int N=114514;
int a[N][3];
int flag[N],flagcnt[N];
struct stc
{
	int oripos,value;
}tttmp[N];
int f(int a,int b,int c)
{
	int mx=max(a,max(b,c));
	int mn=min(a,min(b,c));
	int maxid=((mx==a)?1:((mx==b)?2:3));
	int minid=((mn==a)?1:((mn==b)?2:3));
	int midid=6-maxid-minid;
	return mx-((midid==1)?a:((midid==2)?b:c));
}
bool cmp(stc a,stc b)
{
	return a.value<b.value;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		memset(a,-1,sizeof(a));
		memset(flagcnt,0,sizeof(flagcnt));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			tttmp[i].oripos=-1,tttmp[i].value=0;
		}
		int tmpret=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			flag[i]=((mx==a[i][1])?1:((mx==a[i][2])?2:3));
			flagcnt[flag[i]]++;
			tmpret+=mx;
		}
		int whoof=0,upper=n/2,howmuch;
		if(flagcnt[1]>upper)
		{
			whoof=1;
			howmuch=flagcnt[1]-upper;
		}
		else if(flagcnt[2]>upper)
		{
			whoof=2;
			howmuch=flagcnt[2]-upper;
		}
		else if(flagcnt[3]>upper)
		{
			whoof=3;
			howmuch=flagcnt[3]-upper;
		}
		if(whoof==0)
		{
			cout<<tmpret<<endl;
			continue;
		}
		int tmpi=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==whoof)
			{
				tmpi++;
				tttmp[tmpi].value=f(a[i][1],a[i][2],a[i][3]);
				tttmp[tmpi].oripos=i;
			}
		}
		sort(tttmp+1,tttmp+tmpi+1,cmp);
		for(int i=1;i<=howmuch;i++)
		{
			tmpret-=tttmp[i].value;
		}
		cout<<tmpret<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}