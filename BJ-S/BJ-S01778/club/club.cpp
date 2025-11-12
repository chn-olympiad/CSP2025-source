#include<bits/stdc++.h>
using namespace std;
long long ans,a[10001][10001],n,m,step1,step2,step3;
int f(long long step,long long sum,int a1,int a2,int a3)
{
	if(step<=0) 
	{
		return sum;
	}
	if(a1<0 || a2<0 || a3<0)
	{
		sum=0;
		return 0;
	}
	long long a11=a1,a21=a2,a31=a3;
	step1=step,step2=step,step3=step;
	return sum=max(f(--step1,sum+a[step1][1],--a11,a2,a3),max(f(--step2,sum+a[step2][2],a1,--a21,a3),f(--step3,sum+a[step3][3],a1,a2,--a31)));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		int mm=m/2;
		
		
		for(int j=1;j<=m;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		ans=0;
		ans=f(n,0,mm,mm,mm);
		cout<<ans;
	}
	return 0;
	//Ren5Jie4Di4Ling5%
}
