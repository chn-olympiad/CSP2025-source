//GZ-S00109 毕节七星关东辰实验学校 周泰丞
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int q[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	string str;
	cin>>str;
	int wei=1;
	for(int i=0;i<=str.size()-1;i++)
	{
		if(str[i]=='0')
		{
			wei++;
			continue;
		}
		if(str[i]=='1')
			q[wei]++;
	}
	int a=1,b=1,c=1;
	for(int i=1;i<=n;i++)a*=i;
	for(int i=1;i<=q[1];i++)b*=i;
	for(int i=1;i<=n-q[1];i++)c*=i;
	long long ans=a/(b*c);
	printf("%lld",ans);
	return 0;
} 
