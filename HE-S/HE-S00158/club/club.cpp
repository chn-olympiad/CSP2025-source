#include<bits/stdc++.h>
using namespace std;
int t,n;
//定义三个变量表示三个部门
int a,b,c;
//定义一个数据类型包含三个变量
struct chy
{
	int a1;
	int b1;
	int c1;
	char bm;//表示最终被分到了哪个部门 
};
//定义几个个数组
chy my[100005]; 	
int a2[100005],b2[100005],c2[100005];
//定义一个球最大值的函数 
int max(int i)
{
	int max1=my[i].a1;
	if(my[i].b1>max1)
	{
		max1=my[i].b1;
	}
	if(my[i].c1>max1)
	{
		max1=my[i].c1;
	}
	return max1;
}
int a3[100005][4],b3[100005][4],c3[100005][4];
//定义一个降序排列数组的函数 
void f(int x[],int num)
{
	for(int i=0;i<=num;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(x[j]<x[j+1])
			{
				int tmp=x[j];
				x[j]=x[j+1];
				x[j+1]=tmp;
			}
		}
	}
	return ;
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//输入
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int num=0;
		//输入n
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			//输入数组
			cin>>my[i].a1>>my[i].b1>>my[i].c1; 
			int max1=max(i);
			if(max1==my[i].a1)
			{
				a++;
				my[i].bm='a';
				num+=my[i].a1;
			}
			else if(max1==my[i].b1)
			{
				b++;
				my[i].bm='b';
				num+=my[i].b1;
			}
			else if(max1==my[i].c1)
			{
				c++;
				my[i].bm='c';
				num+=my[i].c1;
			}
		}
		//判断人数是否超出
		if(a>n/2) 
		{
			//便利数组
			int o=0;
			for(int i=1;i<=n;i++)
			{
				if(my[i].bm=='a')
				{
					a2[o]=my[i].a1;
					a3[o][1]=my[i].a1;
					a3[o][2]=my[i].b1;
					a3[o][3]=my[i].c1;
					num=num-my[i].a1;
					o++;
				}
			}
			//将数组变为降序排列
			f(a2,o);
			//验证输出
//			for(int i=0;i<o;i++)
//			{
//				cout<<a2[i]<<" "; 
//			} 
			//让后(o-n/2)个人重新选择
			//取出前n/2个数
			for(int i=0;i<n/2;i++) 
			{
				num+=a2[i];
			}
			for(int i=n/2-1;i<o;i++) 
			{
				for(int j=1;j<=o;j++)
				{
					if(a3[j][1]==a2[i])
					{
						if(a3[j][2]>a3[j][3])
						{
							num+=a3[j][2];
						}
						else
						{
							num+=a3[j][3];
						}
					}
				}
			}
					
		}
		if(b>n/2)
		{
			//便利数组
			int o=0;
			for(int i=1;i<=n;i++)
			{
				if(my[i].bm=='b')
				{
					b2[o]=my[i].b1;
					b3[o][1]=my[i].a1;
					b3[o][2]=my[i].b1;
					b3[o][3]=my[i].c1;
					num=num-my[i].b1;
					o++;
				}
			}
			//将数组变为降序排列
			f(b2,o);
			//验证输出
//			for(int i=0;i<o;i++)
//			{
//				cout<<a2[i]<<" "; 
//			} 
			//让后(o-n/2)个人重新选择
			//取出前n/2个数
			for(int i=0;i<n/2;i++) 
			{
				num+=b2[i];
			}
			for(int i=n/2-1;i<o;i++) 
			{
				for(int j=1;j<=o;j++)
				{
					if(b3[j][1]==b2[i])
					{
						if(b3[j][2]>b3[j][3])
						{
							num+=b3[j][2];
						}
						else
						{
							num+=b3[j][3];
						}
					}
				}
			}
		}
		if(c>n/2)
		{
			//便利数组
			int o=0;
			for(int i=1;i<=n;i++)
			{
				if(my[i].bm=='c')
				{
					c2[o]=my[i].a1;
					c3[o][1]=my[i].a1;
					c3[o][2]=my[i].b1;
					c3[o][3]=my[i].c1;
					num=num-my[i].c1;
					o++;
				}
			}
			//将数组变为降序排列
			f(c2,o);
			//验证输出
//			for(int i=0;i<o;i++)
//			{
//				cout<<a2[i]<<" "; 
//			} 
			//让后(o-n/2)个人重新选择
			//取出前n/2个数
			for(int i=0;i<n/2;i++) 
			{
				num+=c2[i];
			}
			for(int i=n/2-1;i<o;i++) 
			{
				for(int j=1;j<=o;j++)
				{
					if(c3[j][1]==c2[i])
					{
						if(c3[j][2]>c3[j][3])
						{
							num+=c3[j][2];
						}
						else
						{
							num+=c3[j][3];
						}
					}
				}
			}
		}
		//输出
		cout<<num<<endl; 
	} 
	
	
	return 0;
	//保存时记得解注释 
 } 
