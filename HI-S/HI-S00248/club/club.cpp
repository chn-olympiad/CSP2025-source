#include<bits/stdc++.h> 
using namespace std;
int t,n,l[4];
struct E{
	int w,id;
}a[4][100006];
//a[100004][4];]
int dui[4]={0,1,2,3};
priority_queue<int> q[4];
//bool cmp(int a,int b)
//{
//	return a>b;
//}
int d[300006],f[103][104][104];
bool k=false,vis[100003];
bool u=false;
//void pd(int i)
//{
//	for(int j=1;j<=3;j++)
//	{
//		if(l[j]<n/2)
//		{
//			q[j].push(a[j][i].w);
//			l[j]++;
//			cout<<"加"<<j<<" "<<a[j][i].id<<' '<<a[j][i].w<<endl;
//		} 之前代码 
//		
//		if(maxx==j)
//		{
//			
//			if(l[j]<n/2)
//			{
//				q[j].push(maxx);
//				l[j]++;
//				if(j==1)
//				{
//					
//				}
//				if(j==2)
//				{
//					cout<<"加"<<j<<" "<<a2[i].id<<' '<<maxx<<endl; 
//				}
//				else
//				{
//					cout<<"加"<<j<<" "<<a3[i].id<<' '<<maxx<<endl; 
//				}
//			}
//		}
//	}
//如果没有满的话就全加上 
//}
int main()
{
	int f=1;
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
//	cout<<200*100*100*100/(1024*2*1024);
	for(int sm=1;sm<=t;sm++)
	{
		memset(vis,true,sizeof(vis));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i].w>>a[2][i].w>>a[3][i].w;
			for(int j=1;j<=3;j++)
				d[f++]=a[j][i].w;
			
			
			if(a[2][i].w!=0)
			{
				u=true;//u是两个都不的 
				if(a[3][i].w!=0)
					k=true;
			}
		}
		if(n<=200)
		{
//			sort(a[2]+1,a[2]+1+n,cmp);
//			sort(a[3]+1,a[3]+1+n,cmp);
//			sort(a[1]+1,a[1]+1+n,cmp);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					for(int z=1;z<=n;z++)
					{
					//	f[i][j][z]=max(f[i][j][z],)
					}
				}
			}
		}
		if(n>200)
		{

			
		}
		if(!u)
		{
			cout<<"可以直接输出最大的n/2个";
			
			
			sort(d+1,d+1+3*n);
			for(int i=3*n;i>3*n-n/2;i--)
			{
				cout<<d[i];
			}
		}
		else
		{
			//tan();
		}
		memset(l,0,sizeof(l));

//		for(int i=1;i<=n;i++)
//		{
//			cout<<a1[i].w<<" "<<a1[i].id<<endl;
//		}
//		while(!q1.empty())
//		{
//			cout<<q1.top()<<' ';
//			q1.pop();
//		}
//		cout<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			
//		}
	//	int p1=1,p2=1;
//		for(int i=1;i<=n;i++)
//		{
//			pd(i);
//		}
		cout<<"下一个"<<endl;
	}	
	
	return 0;
}
