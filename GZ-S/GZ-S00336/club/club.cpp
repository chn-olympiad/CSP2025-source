//GZ-S00336 贵阳市第十八中学 王相宇
#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010][5],b1[100010],b2[100010],b3[100010],sl,a1,a2,a3;//sl最多分配人数  a累计每组（st）满意度  b数组累计每人1,2,3满意度最高的  q数量 
bool cmd(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int z=0;
	for(int y=1;y<=t;y++)
	{
		a1=0,a2=0,a3=0;
		long long sum=0;
		cin>>n;
		sl=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];	
			}
			b1[i]=a[i][1],b2[i]=a[i][2],b3[i]=a[i][3];
//			int qwq; 
//			qwq=max(a[i][1],max(a[i][2],a[i][3]));
//			if(qwq==a[i][1])
//			{
//				b1[i]=qwq;
//				q1++;
//			}
//			else if(qwq==a[i][2])
//			{
//				b2[i]=qwq;
//				q2++;
//			}
//			else 
//			{
//				b3[i]=qwq;
//				q3++;
//			}
		}
		sort(b1+1,b1+n+1,cmd);
		sort(b2+1,b2+n+1,cmd);
		sort(b3+1,b3+n+1,cmd);
//		for(int i=1;i<=n;i++)
//		{
//			cout<<b1[i]<<b2[i]<<b3[i];
//		}
		for(int i=1;i<=n/2;i++)
		{
			a1+=b1[i],a2+=b2[i],a3+=b3[i];	
			//cout<<a1<<'1'<<a2<<'9'<<a3<<'7';
		} 
		//cout<<a1<<' '<<a2<<' '<<a3<<' ';
				
		
		
		
		bool sss=1;
		for(int i=1;i<=n;i++)
		{
			if(b3[i]!=0)sss=0;
		}
		if(sss)
		{
			int v=0,vv=0;
			for(int i=1;i<=n;i++)
			{
				if(b1[i]>=b2[i]&&v<sl)
				{
					sum+=b1[i];
					v++;
				}
				else 
				{
					sum+=b2[i];
					vv++;
				}
			}
			cout<<sum;
			continue;
		}




		sum+=max(a1,max(a2,a3)); 
		if(sum==a1)z=1;
		else if(sum==a2)z=2;
		else z=3;
		//cout<<2;
		for(int i=1;i<=n/2;i++)
		{
			//cout<<1;
			if(z==1)
			{
				//cout<<1;
				sum+=max(b2[i],b3[i]);
			}
			else if(z==2)
			{
				sum+=max(b1[i],b3[i]);
			}
			else sum+=max(b1[i],b3[i]);
		}
		cout<<sum<<endl;
	}
	
	//cout<<z;	
	return 0;
}
