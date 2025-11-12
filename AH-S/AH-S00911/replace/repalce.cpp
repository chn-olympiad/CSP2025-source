#include<iostream>
#include<cstring>
using namespace std;
string p[200005][3];
long long n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>p[i][1]>>p[i][2];
	for(int i=1;i<=q;i++)
	{
		long long sum=0;
		string x,y;
		cin>>x>>y;
		for(int j=1;j<=int(x.size());j++) //枚举开头
		{
			for(int k=j;k<=int(x.size());k++) //枚举结尾
			{
				for(int w1=1;w1<=n;w1++)//枚举第几对
				{
					if(int(p[w1][1].size())!=k-j+1) continue;
					string t1;
					for(int w2=j-1;w2<=k-1;w2++)
						t1+=x[w2];
					if(t1==p[w1][1])
					{
						string t3=x;
						for(int w2=j-1;w2<=k-1;w2++)
						{
							t3[w2]=p[w1][2][w2-j+1];
						}
						if(t3==y){
						sum++;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
