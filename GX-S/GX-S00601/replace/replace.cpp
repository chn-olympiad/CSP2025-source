#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<ctime>
#include<cstdlib>
#define int long long
const int N=211985;
const int M=1000000007;
using namespace std;
char cvb;
int re()
{
	int dfg=0,fgh=1;
	cvb=getchar();
	while(cvb>'9'||cvb<'0')
	{
		if(cvb=='-') fgh=-1;
	cvb=getchar();
		}
	while(cvb>='0'&&cvb<='9')
	{
		dfg=(dfg<<1)+(dfg<<3)+cvb-'0';
	cvb=getchar();
		}
	return dfg*fgh;
}
int n,q,l[N],r[N],L,R,len[N],LL,ans;
string s[N][2],p[2];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=re();
	q=re();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		len[i]=s[i][0].size();
		LL+=len[i];
		l[i]=1;
		r[i]=0;
		for(int j=0;j<len[i];j++)
		  if(s[i][0][j]!=s[i][1][j]) {l[i]=j; break;}
		for(int j=len[i];j>=0;j--)
		  if(s[i][0][j]!=s[i][1][j]) {r[i]=j; break;}
    }
	//cout<<LL<<endl;
    //q=re();
    while(q--)
    {
		ans=0;
	cin>>p[0]>>p[1];
	if(p[0].size()!=p[1].size()) {printf("0\n"); continue;}
	len[0]=p[0].size();
	for(int j=0;j<len[0];j++)
		  if(p[0][j]!=p[1][j]) {L=j; break;}
		for(int j=len[0];j>=0;j--)
		  if(p[0][j]!=p[1][j]) {R=j; break;}
    if(LL<=2000) //25pts
    {
	    for(int j=1;j<=n;j++)
	    {
			if(R-L!=r[j]-l[j]) continue;
			if(L-l[j]<0||R+len[j]-1-r[j]>=len[0]) continue;
			for(int k=L-l[j];k<=R+len[j]-1-r[j];k++)
			{
				if(p[0][k]!=s[j][0][k+l[j]-L]||p[1][k]!=s[j][1][k+l[j]-L]) break;
				if(k==R+len[j]-1-r[j]) ans++;
				}
		}
		printf("%lld\n",ans);
	}
    else //B
    {
		for(int j=1;j<=n;j++)
		{
			if(R-L!=r[j]-l[j]) continue;
			if(L-l[j]<0||R+len[j]-1-r[j]>=len[0]) continue;
			if(p[0][L]!=s[j][0][l[j]]) continue;
			ans++;
		}
		printf("%lld\n",ans);
	}
}
	return 0;   // A can be done by Hash(maybe),but no time left
}
