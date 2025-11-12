#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[100005][4];

int bumena[100005],bumenb[100005],bumenc[100005];
int numa=0,numb=0,numc=0;

int cmp(int i,int j)
{
	int p1,cmax1;
	if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) p1=1;
	else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) p1=2;
	else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) p1=3;
	if(p1==1) cmax1=max(a[i][2],a[i][3]);
	if(p1==2) cmax1=max(a[i][1],a[i][3]);
	if(p1==3) cmax1=max(a[i][2],a[i][1]);
	
	int p2,cmax2;
	if(a[j][1]>=a[j][2]&&a[j][1]>=a[j][3]) p2=1;
	else if(a[j][2]>=a[j][1]&&a[j][2]>=a[j][3]) p2=2;
	else if(a[j][3]>=a[j][1]&&a[j][3]>=a[j][2]) p2=3;
	if(p2==1) cmax2=max(a[j][2],a[j][3]);
	if(p2==2) cmax2=max(a[j][1],a[j][3]);
	if(p2==3) cmax2=max(a[j][2],a[j][1]);
	return (a[i][p1]-cmax1)>(a[j][p2]-cmax2);
	
}
void yun(int bumen[],int num,long long &ans,int p)
{
	sort(bumen+1,bumen+1+num,cmp);
	for(int i=num;i>n/2;i--)
	{
		int cmax=0;
		if(p==1) cmax=max(a[bumen[i]][2],a[bumen[i]][3]);
		if(p==2) cmax=max(a[bumen[i]][1],a[bumen[i]][3]);
		if(p==3) cmax=max(a[bumen[i]][2],a[bumen[i]][1]);
		ans-=a[bumen[i]][p];
		ans+=cmax;
	}
}

signed main()
{
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {

        long long ans=0;
        cin>>n;
        numa=0,numb=0,numc=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) bumena[++numa]=i,ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) bumenb[++numb]=i,ans+=a[i][2];
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) bumenc[++numc]=i,ans+=a[i][3];
		}
		if(numa>n/2) yun(bumena,numa,ans,1);
		else if(numb>n/2) yun(bumenb,numb,ans,2);
		else if(numc>n/2) yun(bumenc,numc,ans,3);
		cout<<ans<<"\n";
    }
    return 0;
}
