#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
int t,n,a[200001][4];
int x1,x2,x3,y11[2][200001],y2[2][200001],y3[2][200001],sum1,sum2,sum3,ans=0;
int max(int c,int d)
{
	if(c>=d)return c;
	else return d;
}
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++)
{
	cin>>n;
	x1=0;x2=0;x3=0;ans=0;sum1=0;sum2=0;sum3=0;
	for(int j=1;j<=n;j++)
	{
		cin>>a[j][1]>>a[j][2]>>a[j][3];
		if(max(max(a[j][1],a[j][2]),max(a[j][2],a[j][3]))==a[j][1]){sum1+=a[j][1];a[j][1]-=max(a[j][2],a[j][3]);x1++;y11[1][j]=a[j][1];y11[0][j]=j;continue;}
		if(max(max(a[j][1],a[j][2]),max(a[j][2],a[j][3]))==a[j][2]){sum2+=a[j][2];a[j][2]-=max(a[j][1],a[j][3]);x2++;y2[1][j]=a[j][2];y2[0][j]=j;continue;}
		if(max(max(a[j][1],a[j][2]),max(a[j][2],a[j][3]))==a[j][3]){sum3+=a[j][3];a[j][3]-=max(a[j][1],a[j][2]);x3++;y3[1][j]=a[j][3];y3[0][j]=j;continue;}
	}
	ans=sum1+sum2+sum3;
	if(x1<=n/2&&x2<=n/2){if(x3<=n/2)cout<<ans<<endl;continue;}
	int maxx=max(max(x1,x2),max(x2,x3));int maxs;if(x1>n/2)maxs=1;if(x2>n/2)maxs=2;if(x3>n/2)maxs=3;
	if(maxs==1)
	{
		sort(y11[0]+1,y11[0]+n+1,[&](int x,int y){
		return y11[1][x]<y11[1][y];});
		for(int j=1;j<=maxx-n/2;j++){ans-=a[y11[0][j]][1];}
	}
	if(maxs==2)
	{
		sort(y2[0]+1,y2[0]+n+1,[&](int x,int y){
		return y2[1][x]<y2[1][y];});
		for(int j=1;j<=maxx-n/2;j++){ans-=a[y2[0][j]][2];}
	}
	if(maxs==3)
	{
		sort(y3[0]+1,y3[0]+n+1,[&](int x,int y){
		return y3[1][x]<y3[1][y];});
		for(int j=1;j<=maxx-n/2;j++){ans-=a[y3[0][j]][3];}
	}
	cout<<ans<<' '<<endl;
}
return 0;
}
