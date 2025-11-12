//GZ-S00276 贵阳中天中学 杨雨辰
#include<bits/stdc++.h>
using namespace std;
struct club
{
	int fst,sec,thr;
	int mx;
};
club a[100001],fst[100001],sec[100001],thr[100001];
int sf,ss,st,tj;
bool p[100001];
bool CmpF(club x,club y)
{
	return x.fst>y.fst;
}
bool CmpS(club x,club y)
{
	return x.sec>y.sec;
}
bool CmpT(club x,club y)
{
	return x.thr>y.thr;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n=0,t=0,sum=0;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		sf=0;
		ss=0;
		st=0;
		tj=0;
		memset(p,0,sizeof p);
	    for(int i=0;i<n;i++) 
		{
		    scanf("%d%d%d",&a[i].fst,&a[i].sec,&a[i].thr);
			a[i].mx=i;
			fst[i]=a[i];
		}
	    sort(fst,fst+n,CmpF);
	    int s=0;
	    for(int i=0;i<n/2;i++)
	    {
			sum+=fst[i].fst;
		}    
	    printf("%d\n",sum);
    } 
    fclose(stdin);
    fclose(stdout);
}
