#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,n1,n2,n3,num;
long long ans;
struct happy
{
	int a1;
	int a2;
	int a3;
	int n1_2;
	int n2_3;
	int n1_3;
};
bool cmp1(happy c,happy d)
{
	return(c.n1_2<d.n1_2);
}
bool cmp2(happy c,happy d)
{
	return(c.n1_3<d.n1_3);	
}
bool cmp3(happy c,happy d)
{
	return(c.n2_3<d.n2_3);	
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	happy a[N],p1[N],p2[N],p3[N],p1_2[N],p1_3[N],p2_1[N],p2_3[N],p3_1[N],p3_2[N];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		
		ans=0;n1=0;n2=0;n3=0;n=0;num=0;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			a[j].n1_2=abs(a[j].a1-a[j].a2);
			a[j].n2_3=abs(a[j].a2-a[j].a3);
			a[j].n1_3=abs(a[j].a1-a[j].a3);
			if(a[j].a1>a[j].a2 &&a[j].a1>a[j].a3)
			{
				ans+=a[j].a1;
				n1++;
				p1[j]=a[j];
				p1_2[j]=a[j];
				p1_3[j]=a[j];			
			}
			else if(a[j].a2>a[j].a1 &&a[j].a2>a[j].a3)
			{
				ans+=a[j].a2;
				n2++;
	
				p2[j]=a[j];
				p2_1[j]=a[j];	
				p2_3[j]=a[j];								
			}
			else
			{
				ans+=a[j].a3;
				n3++;

				p3[j]=a[j];
				p3_1[j]=a[j];
				p3_2[j]=a[j];
				
			}
		}
		if(n1>n/2)
		{
			//cout<<"111"<<endl;
			sort(p1_2+1,p1_2+n1+1,cmp1);
			sort(p1_3+1,p1_3+n1+1,cmp2);
						
			int num=1;
			while(n1>n/2)
			{
				//cout<<ans<<endl;
				long long cnt1=(p1_2[num].a1-p1_2[num].a2),cnt2=(p1_3[num].a1-p1_3[num].a3);
				if(cnt1<cnt2 && n2+1<=n/2)
				{
					ans-=cnt1;
					n2++;
					n1--;
					num++;
				}
				else if(cnt1<cnt2 && n2+1>n/2)
				{
					ans-=cnt2;
					n3++;
					n1--;	
					num++;				
				}
				else if(cnt1>cnt2 && n3+1<=n/2)
				{
					ans-=cnt2;
					n3++;
					n1--;
					num++;
				}
				else if(cnt1>cnt2 && n3+1>n/2)
				{
					ans-=cnt1;
					n2++;
					n1--;
					num++;
				}
				else if(cnt1==cnt2)
				{
					if(n2+1>n/2)
					{
						ans-=cnt2;
						n3++;
						n1--;		
						num++;				
					}
					else
					{
						ans-=cnt1;
						n2++;
						n1--;
						num++;
					}
				}
			}			
		}
		else if(n2>n/2)
		{
			//cout<<"222"<<endl;
			sort(p2_1+1,p2_1+n2+1,cmp1);
			sort(p2_3+1,p2_3+n2+1,cmp3);
								
			int num=1;
			while(n2>n/2)
			{
				long long cnt1=p2_1[num].a2-p2_1[num].a1,cnt2=p2_3[num].a2-p2_3[num].a3;
				if(cnt1<cnt2 && n1+1<=n/2)
				{
					ans-=cnt1;
					n1++;
					n2--;
					num++;
				}
				else if(cnt1<cnt2 && n1+1>n/2)
				{
					ans-=cnt2;
					n3++;
					n2--;
					num++;					
				}
				else if(cnt1>cnt2 && n3+1<=n/2)
				{
					ans-=cnt2;
					n3++;
					n2--;
					num++;
				}
				else if(cnt1>cnt2 && n3+1>n/2)
				{
					ans-=cnt1;
					n1++;
					n2--;
					num++;
				}
				else if(cnt1==cnt2)
				{
					if(n1+1>n/2)
					{
						ans-=cnt2;
						n3++;
						n2--;	
						num++;					
					}
					else
					{
						ans-=cnt1;
						n1++;
						n2--;
						num++;
					}
				}	
			}			
		}
		else if(n3>n/2)
		{
			//cout<<"333"<<endl;
			sort(p3_2+1,p3_2+n3+1,cmp3);
			sort(p3_1+1,p3_1+n3+1,cmp2);				
			int num=1;
			while(n3>n/2)
			{
				long long cnt1=(p3_2[num].a3-p3_2[num].a2),cnt2=(p3_1[num].a3-p3_1[num].a1);
				if(cnt1<cnt2 && n2+1<=n/2)
				{
					ans-=cnt1;
					n2++;
					n3--;
					num++;
				}
				else if(cnt1<cnt2 && n2+1>n/2)
				{
					ans-=cnt2;
					n1++;
					n3--;	
					num++;				
				}
				else if(cnt1>cnt2 && n1+1<=n/2)
				{
					ans-=cnt2;
					n1++;
					n3--;
					num++;
				}
				else if(cnt1>cnt2 && n1+1>n/2)
				{
					ans-=cnt1;
					n2++;
					n3--;
					num++;
				}
				else if(cnt1==cnt2)
				{
					if(n2+1>n/2)
					{
						ans-=cnt2;
						n1++;
						n3--;
						num++;						
					}
					else
					{
						ans-=cnt1;
						n2++;
						n3--;
						num++;
					}
				}
			}			
		}
		
		cout<<ans<<endl;			
	}
	
	return 0;
}
