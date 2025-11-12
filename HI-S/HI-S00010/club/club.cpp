#include <bits/stdc++.h>
using namespace std;
int T,n;int ans;int b[100086];int b1,b2,b3;int c[100086];
struct node
{
	int c1,c2,c3,c4,num;
	int t0,t1,t2,t3;int f1,f2;
}a[100086];
int cmp(node x,node y)
{
	return x.c1>y.c1||(x.c1==y.c1&&x.c2>y.c2)||(x.c1==y.c1&&x.c2==y.c2&&x.c3>y.c3);
}
int cmp1(node x,node y)
{
	return x.t1>y.t1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		b1=0;b2=0;b3=0;
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			a[i].num=i;
			//a[i].t0=max(a[i].c1,max(a[i].c2,a[i].c3));
			
			if(a[i].c1>a[i].c2&&a[i].c1>a[i].c3)
			{
				a[i].t0=a[i].c1;
				b[i]=1;
				//b1++;
			//	continue;
			}
			else if(a[i].c2>a[i].c1&&a[i].c2>a[i].c3)
			{
				a[i].t0=a[i].c2;
				b[i]=2;
			//	b2++;
			//	continue;
			}
			else if(a[i].c3>a[i].c1&&a[i].c3>a[i].c2)
			{
				a[i].t0=a[i].c3;
				b[i]=3;
			//	b3++;
			//	continue;
			}
			else if(a[i].c2==a[i].c1&&a[i].c2>a[i].c3)
			{
				a[i].t0=a[i].c1;
				b[i]=1;
			//	b1++;
			//	continue;
			}
			else if(a[i].c2==a[i].c3&&a[i].c2>a[i].c1)
			{
				a[i].t0=a[i].c2;
				b[i]=2;
			//	b2++;
			//	continue;
			}
			else if(a[i].c1>a[i].c2&&a[i].c1==a[i].c3)
			{
				a[i].t0=a[i].c1;
				b[i]=1;
			//	b1++;
			//	continue;
			}
			ans+=a[i].t0;
			/*if(a[i].t0=a[i].c1)
			{
				
				b[i]=1;
				b1++;
				c[i]=a[i].t0;
			}
			else if(a[i].t0==a[i].c2)
			{
				
				b[i]=2;
				b2++;
				c[i]=a[i].t0;
			}
			else if(a[i].t0==a[i].c3)
			{
				
				b[i]=3;
				b3++;
				c[i]=a[i].t0;
			}*/
		}
		//cout<<b1<<" "<<b2<<" "<<b3<<endl;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				b1+=1;
				a[i].f2=1;
			}
			if(b[i]==2)
			{
				b2+=1;
				a[i].f2=2;
			}
			if(b[i]==3)
			{
				b3+=1;
				a[i].f2=3;
			}
		}
		//cout<<b1<<" "<<b2<<" "<<b3<<endl;
			for(int i=1;i<=n;i++)
			{
				if(b[i]==1)
				{
					if(a[i].c2-a[i].t0>=a[i].c3-a[i].t0)
					{
						a[i].f1=2;
						a[i].t1=a[i].c2-a[i].t0;
					}
					else if(a[i].c2-a[i].t0<a[i].c3-a[i].t0)
					{
						a[i].f1=3;
						a[i].t1=a[i].c3-a[i].t0;
					}
				}
				else if(b[i]==2)
				{
					if(a[i].c1-a[i].t0>=a[i].c3-a[i].t0)
					{
						a[i].f1=1;
						a[i].t1=a[i].c1-a[i].t0;
					}
					else if(a[i].c1-a[i].t0<a[i].c3-a[i].t0)
					{
						a[i].f1=3;
						a[i].t1=a[i].c3-a[i].t0;
					}
				}
				else if(b[i]==3)
				{
					if(a[i].c1-a[i].t0>=a[i].c2-a[i].t0)
					{
						a[i].f1=1;
						a[i].t1=a[i].c1-a[i].t0;
					}
					else if(a[i].c1-a[i].t0<a[i].c2-a[i].t0)
					{
						a[i].f1=2;
						a[i].t1=a[i].c2-a[i].t0;
					}
				}
				//cout<<a[i].t1<<" ";
			 } 
			 //cout<<endl;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
		//	cout<<a[i].t1<<" "<<a[i].num<<" "<<a[i].f1<<endl;
		}
		int i=1;
		if(b1>(n/2))
		{
			//for(int i=1;i<=n;i++)
			while(b1>(n/2))
			{
			//	cout<<" "<<ans<<" "<<a[i].num<<" ";
				if(a[i].f1!=1&&a[i].f2==1)
				{
					ans+=a[i].t1;
				//	cout<<b1<<" ";
					b1-=1;
					/*if(b1<=(n/2))
					{
					break;
					}*/
				}
				i++;
			}
		}
		if(b2>(n/2))
		{
			//for(int i=1;i<=n;i++)
			while(b2>(n/2))
			{
			//	cout<<" "<<ans<<" "<<a[i].num<<" ";
				if(a[i].f1!=2&&a[i].f2==2)
				{
					ans+=a[i].t1;
				//	cout<<b2<<" ";
					b2--;
					/*if(b2<=(n/2))
					{
					break;
					}*/
				}
				i++;
			}
		}
		if(b3>(n/2))
		{
			//for(int i=1;i<=n;i++)
			while(b3>(n/2))
			{
			//	cout<<" "<<ans<<" "<<a[i].num<<" ";
				if(a[i].f1!=3&&a[i].f2==3)
				{
					
					ans+=a[i].t1;
				//	cout<<b3<<" ";
					b3--;
					/*if(b3<=(n/2))
					{
						break;
					}*/
				}
				i++;
			}
		}
		/*sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			
			
		}//预处理 
		if(b1>n/2)//若有多于n/2的情况再处理 
		{
			
		}*/
		
		cout<<ans<<endl;
	}
	return 0;
} 
