#include<bits/stdc++.h>
using namespace std;
int a[100010][4],n,t,q[4],m,cc,r[100010],cha[100010],ans,s,maxn,tmp,tmpi,h;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
	cin>>n;ans=0;q[1]=0;q[2]=0;q[3]=0;
	for(int i=1;i<=n;i++)
	{
		tmp=0;r[i]=1;
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
			
			if(tmp<a[i][j]){
				tmp=a[i][j];
				r[i]=j;
			}
		}
		ans+=tmp;q[r[i]]++;
	}
	if(q[1]<=n/2&&q[2]<=n/2&&q[3]<=n/2)
	{
		cout<<ans<<endl;
	}
	else{
	
	if(q[1]>n/2)h=1;if(q[2]>n/2)h=2;if(q[3]>n/2)h=3;
	cc=0;
	for(int i=1;i<=n;i++)
	{
		if(r[i]!=h)continue;
		else {
			cha[++cc]=199999999;
			for(int j=1;j<=3;j++)if(j!=h)cha[cc]=min(cha[cc],abs(a[i][r[i]]-a[i][j]));
		}
	}
	if(cc>0)sort(cha+1,cha+cc);
	for(int i=1;i<=(q[h]-(n/2));i++)
	{
		ans-=cha[i];
	}
	cout<<ans<<endl;}
	
	}
	return 0;
} 
