#include<bits/stdc++.h>//freoepn
using namespace std;
int a[500005];//yuanshu
int b[500005];//tongji
bool c[500005];
void f(int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		c[i]=true;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==true)
		{
			continue;
		}
		for(int j=i;j<=n;j++)
		{
			if(c[j]==true)
			{
				continue;
			}
			if(c[i]==true)
			{
				break;
			}
			/*if(i==j)
			{
				if(a[i]==k)
				{
					num++;
					c[i]=true;
				}
				continue;
			}*/
			//cout<<b[j]<<" "<<b[i-1]<<" "<<(b[j]|b[i-1])<<endl;
			int t=(b[j]^b[i-1]);
			//cout<<"i="<<i<<" "<<"j="<<j<<" "<<"b[j]="<<b[j]<<" "<<"b[i-1]="<<b[i-1]<<" "<<"t="<<t<<endl;
			if(t==k)
			{
				//cout<<"nn1n1"<<endl;
				num++;
				f(i,j);
			}
		}		
	}
	cout<<num;//无语，只对了5个测试点，15个测试点都没了
	return 0;
}