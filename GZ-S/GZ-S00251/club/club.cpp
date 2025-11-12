//杜庹钊
//GZ-S00251
//安顺市第一高级中学

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

#define int long long
//ORZ//ORZ

using namespace std;
const int N=100050;
int a[N],b[N],c[N];
int total[5];
int set[N][5];

int Max(int a,int b,int c)
{
	int l=0;
	l=max(a,b);
	if(l==max(a,c))
		return 1;
	else if(l==max(b,c))
		return 2;
	else if(l==c)
		return 3;
}

int Max1(int a,int b,int c)
{
	int l=0;
	l=max(a,b);
	l=max(l,c);
	return l;
}

int bro(int a,int b,int c)	//a为最大值 
{
	return a-max(b,c);
}		//找最大值与其他值差的最小值 

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while( T-- )
	{
		int n;
		cin>>n;
		int MAX=n/2;
		int k[N];
		int num[N]={0};
		int sum=0;
		
		for( int i=1 ; i<=n ; ++i )
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		
		/*for( int i=1 ; i<=n ; ++i )
		{
			cout<<a[i]<<"\\"<<b[i]<<"\\"<<c[i]<<"\n";
		}*/
		
		for( int i=1 ; i<=n ; ++i )
		{
			//cout<<"Max(a["<<i<<"],b["<<i<<"],c["<<i<<"]) is "<<Max(a[i],b[i],c[i])<<"\n";
			int q=Max(a[i],b[i],c[i]);
			total[q]++;
			sum+=Max1(a[i],b[i],c[i]);
			set[i][q]=1;
			//cout<<set[i][q];
		}
		
		if(total[1]<=n/2&&total[2]<=n/2&&total[3]<=n/2)
			cout<<sum<<"\n";
			
		else{
			//int neko[N][5]={0};	//存找到的学生 
			//cout<<"sum:"<<sum<<"\n";
			int neko[N]={0};
			int j=0;
			if(total[1]>n/2)
			{
				for(int i=1;i<=n;++i)
				{
					
					if(set[i][1])
					{
						j++;
						/*neko[j][1]=a[i];
						neko[j][2]=bro(a[i],b[i],c[i]);*/
						neko[j]=bro(a[i],b[i],c[i]);
						
						}
					}	//neko初始化完毕，接下来查找其中最小的total-n/2个数
				
				
				/*cout<<"j:"<<j<<"\n";*/		
				sort(neko+1,neko+1+j);
				
				/*cout<<"A:";
				for(int i=1;i<=j;++i)
					cout<<neko[i]<<"\\";*/
						
				for(int i=1;i<=j-n/2;++i)
				{
					sum-=neko[i];
				}	
				cout<<sum<<"\n";
			}
			else if(total[2]>n/2)
			{
				for(int i=1;i<=n;++i)
				{
					
					if(set[i][2])
					{
						j++;
						/*neko[j][1]=a[i];
						neko[j][2]=bro(a[i],b[i],c[i]);*/
						neko[j]=bro(b[i],a[i],c[i]);
						
						}
					}	//neko初始化完毕，接下来查找其中最小的total-n/2个数
				
				
				//cout<<"j:"<<j<<"\n";		
				sort(neko+1,neko+1+j);
				
				/*cout<<"B:";	
				for(int i=0;i<=j;++i)
					cout<<neko[i]<<"\\";*/
						
				for(int i=1;i<=j-n/2;++i)
				{
					sum-=neko[i];
				}	
				cout<<sum<<"\n";
			}
			else{
				for(int i=1;i<=n;++i)
				{
					
					if(set[i][3])
					{
						j++;
						/*neko[j][1]=a[i];
						neko[j][2]=bro(a[i],b[i],c[i]);*/
						neko[j]=bro(c[i],a[i],b[i]);
						
						}
					}	//neko初始化完毕，接下来查找其中最小的total-n/2个数
				
				
				//cout<<"j:"<<j<<"\n";		
				sort(neko+1,neko+1+j);
				
				/*cout<<"B:";	
				for(int i=0;i<=j;++i)
					cout<<neko[i]<<"\\";*/
						
				for(int i=1;i<=j-n/2;++i)
				{
					sum-=neko[i];
				}	
				cout<<sum<<"\n";
			}
		}
	}
	
	return 0;
}
