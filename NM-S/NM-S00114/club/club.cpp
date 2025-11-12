#include<bits/stdc++.h>
using namespace std;
struct node{
        int x,y,z,wz;
}a[100005];
int sumx=0,sumy=0,sumz=0,maxx,minn,can,mid,da,xb=1;
long long sum=0,c[10];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
        int n,m,s;
        cin>>n;
        for(int q=1;q<=n;q++)
        {
                int b[100005]={0};
                cin>>m;
                s=m/2;
                for(int i=1;i<=m;i++)
                {
                        scanf("%d",&a[i].x);
                        scanf("%d",&a[i].y);
                        scanf("%d",&a[i].z);
                        maxx=max(a[i].x,a[i].y);
                        maxx=max(maxx,a[i].z);
                        if(maxx==a[i].x)
                        {
                                sumx++;
                                sum+=a[i].x;
                                a[i].wz=1;
                         }
                        if(maxx==a[i].y)
                        {
                                sumy++;
                                sum+=a[i].y;
                                a[i].wz=2;
                        }
                        if(maxx==a[i].z)
                        {
                                sumz++;
                                sum+=a[i].z;
                                a[i].wz=3;
                        }
                }
                if((sumx>s)||(sumy>s)||(sumz>s))
                {
                        maxx=max(sumx,sumy);
                        maxx=max(maxx,sumz);
                        da=maxx;
                        if(maxx==sumx) can=1;
                        if(maxx==sumy) can=2;
                        if(maxx==sumz) can=3;
					for(int k=1;k<=m;k++)
			{
                         	if(can==a[k].wz)
				{
                                 	maxx=max(a[k].x,a[k].y);
					maxx=max(maxx,a[k].z);
					minn=min(a[k].x,a[k].y);
					minn=min(minn,a[k].z);
					mid=a[k].x+a[k].y+a[k].z-maxx-minn;
					b[xb]=maxx-mid;xb++;
				}
			}
                        sort(b+1,b+xb);
			for(int j=1;j<=da-s;j++)
			{
                         	sum-=b[j];
			}
		}
                c[q]=sum;
		sum=0;
		sumx=0;sumy=0;sumz=0;xb=1;
	}
         	for(int i=1;i<=n;i++)
	{
         	cout<<c[i]<<endl;
	}
 fclose(stdin);
    fclose(stdout);
        return 0;
 }

