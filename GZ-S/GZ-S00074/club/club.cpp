//GZ-S00074 遵义市南白中学 卢杰子豪 
#include<fstream>
#include<algorithm>

std::ifstream in("club.in");
std::ofstream out("club.out");

constexpr int msiz = 1e5;
int a[msiz][3];
int main()
{
	int t;
	in>>t;
	while(t--)
	{
		int n,n2;
		in>>n;
		n2 = n>>1;
		for(int i=0;i<n;i++)
			in>>a[i][0]>>a[i][1]>>a[i][2];
		
		int result = -1;
		for(int i=0;i<n;i++)
		{
			bool flag = true;
			int cnt[3]{0,0,0};
			int re = 0;
			for(int j=i;flag||j!=i;j=(j+1)%n)
			{
				flag=false;
				int max = 0,maxp=-1;
				for(int k=0;k<3;k++)
				{
					if(cnt[k]==n2)
						continue;
					if(a[j][k]>max)
					{
						max = a[j][k];
						maxp = k;
					}
				}
				re+=max;
				++cnt[maxp];
			}
			if(re>result)
				result = re;
		}
		
		out<<result<<'\n';
	}
	return 0;
}
