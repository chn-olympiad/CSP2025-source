#include<bits/stdc++.h>
using namespace std;
int t,n,sum[4],maxb,midb,ans;
struct node{
	int st1,st2,st3,fc1;
}a[100100];
bool cmp(node aa,node bb)
{
    return aa.fc1>bb.fc1; 
}
int main()
{
	//¼ÇµÃÉ¾"//"£¡ 
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		sum[0]=sum[1]=sum[2]=sum[3]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) 
	    {
	    	cin>>a[i].st1>>a[i].st2>>a[i].st3;
	    	a[i].fc1=max(max(a[i].st1,a[i].st2),a[i].st3)-(a[i].st1+a[i].st2+a[i].st3-max(max(a[i].st1,a[i].st2),a[i].st3)-min(min(a[i].st1,a[i].st2),a[i].st3));
		}
		sort(a+1,a+n+1,cmp);
		
		/* 
		for(int i=1;i<=n;i++)
		{
			cout<<a[i].st1<<" "<<a[i].st2<<" "<<a[i].st3<<" "<<a[i].fc1<<"\n";
		}
		*/
		
		for(int i=1;i<=n;i++)
		{
			int maxxx=max(max(a[i].st1,a[i].st2),a[i].st3),middd=a[i].st1+a[i].st2+a[i].st3-max(max(a[i].st1,a[i].st2),a[i].st3)-min(min(a[i].st1,a[i].st2),a[i].st3);
			midb=0,maxb=0;
			if(maxxx==a[i].st1)
				maxb=1;
			else if(maxxx==a[i].st2)
				maxb=2;
			else 
			    maxb=3;
			if(middd==a[i].st1&&maxb!=1)
				midb=1;
			else if(middd==a[i].st2&&maxb!=2)
			    midb=2;
			else 
			    midb=3;
			if(sum[maxb]<n/2)
			{
			    /*
			    cout<<" "<<sum[1]<<" "<<sum[2]<<" "<<sum[3]<<"\n";
				*/
				ans+=maxxx;
				sum[maxb]++;
			}
			else
			{
				ans+=middd;
				sum[midb]++;
			}
		}
		cout<<ans<<endl;
	} 
    return 0;	
} 
