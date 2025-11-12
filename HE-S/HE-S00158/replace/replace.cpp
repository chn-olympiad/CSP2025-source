#include<bits/stdc++.h>
using namespace std;
int n,q;
struct er
{
	string a;
	string b;
};
struct qu
{
	string c;
	string d;
};
er x[200005];
qu y[200005];
//定义函数
string jq(string a,int k,int lenc) 
{
	string x;
	for(int i=k;i<=lenc;i++)
	{
		if(i==k)
		{
			x=a[i];
		}
		else
		{
			x+=a[i];
		}
	}
	return x;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	//输入
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].b;
	} 
	for(int i=1;i<=q;i++)
	{
		cin>>y[i].c>>y[i].d; 
	}
	//定义计数器
	int num=0;
	//解决q个问题 
	for(int i=1;i<=q;i++) 
	{
		int lenc=y[i].c.size();
		for(int j=1;j<=n;j++)
		{
			int lena=x[j].a.size();
			for(int k=0;k+lena<=lenc;k++)
			{
				if(x[j].a==jq(y[i].c,k,k+lena-1))
				{
					//将问题中的字串替换
					string z=jq(y[i].c,0,k-1);
					string t=jq(y[i].c,k+lena,n);
					string u=z+x[j].b+t;
					if(u==y[i].d)
					{
						num++;
						//退出找下一种方法 
						break;
					}
				}
			}
		}
		//输出
		cout<<num<<endl; 
		num=0;
	}
	
	
	return 0;
 } 
