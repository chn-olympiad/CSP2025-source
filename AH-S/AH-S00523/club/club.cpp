#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,sum=0;
    int a[100010][6];
    int b[4];
    int c[100010];
    cin>>t;
    int mid,pp,duoyu;
    while(t--)
    {
		for(int i=1;i<=n;i++)
		{
			c[i]=600000;
			a[i][1]=0;a[i][2]=0;a[i][3]=0;
			a[i][4]=0;
			a[i][5]=0;
		}
		sum=0;
		memset(b,0,sizeof(b));
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
		    cin>>a[i][j];
		    a[i][4]=max(a[i][1],max(a[i][2],a[i][3]));
		    if(a[i][4]==a[i][1])a[i][5]=1;
		    else if(a[i][4]==a[i][2])a[i][5]=2;
		    else if(a[i][4]==a[i][3])a[i][5]=3;
		    sum+=a[i][4];
		}
		
		for(int i=1;i<=n;i++)
		b[a[i][5]]++;
		
		
		mid=n/2;
		pp=0;
		duoyu=0;
		
		if(b[1]>mid)
		{
			duoyu=b[1]-mid;
		
			for(int i=1;i<=n;i++)
			{
				if(a[i][5]==1)
				{
					pp=max(a[i][2],a[i][3]);
					c[i]=a[i][1]-pp;
				}
				else 
				c[i]=600000;
			}
	
			sort(c+1,c+n+1);
			
			
			for(int i=1;i<=duoyu;i++)
			sum=sum-c[i];
			cout<<sum<<endl;
		}
		else if(b[2]>mid)
		{
			duoyu=b[2]-mid;
			for(int i=1;i<=n;i++)
			{
				if(a[i][5]==2)
				{
					pp=max(a[i][1],a[i][3]);
					c[i]=a[i][2]-pp;
				}
				else 
				c[i]=600000;
			}
			sort(c+1,c+n+1);
			for(int i=1;i<=duoyu;i++)
			sum=sum-c[i];
			cout<<sum<<endl;
		}
		else if(b[3]>mid)
		{
			duoyu=b[3]-mid;
			for(int i=1;i<=n;i++)
			{
				if(a[i][5]==3)
				{
					pp=max(a[i][2],a[i][1]);
					c[i]=a[i][3]-pp;
				}
				else 
				c[i]=600000;
			}
			sort(c+1,c+n+1);
			for(int i=1;i<=duoyu;i++)
			sum=sum-c[i];
			cout<<sum<<endl;
		}	
		else
		cout<<sum<<endl;
	}
    return 0;
}
