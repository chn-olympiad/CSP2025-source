#include<iostream>
#include<algorithm>
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a[105],f,h,s,cnt=1;
	bool t=0;
	std::cin>>n>>m;
	long long c=n*m;
	for(int i=1;i<=c;i++)
		std::cin>>a[i];
	f=a[1];
	std::sort(a+1,a+c+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[cnt]==f){
					std::cout<<i<<" "<<j<<std::endl;
					t=1;
					break;	
				}
				cnt++;
			}
		}
		else 
		{
			for(int j=m;j>=m;j--)
			{
				if(a[cnt]==f){
					std::cout<<i<<" "<<j<<std::endl;
					t=1;
					break;
				}
				cnt++;
			}
		}
		if(t)break;
	}
	return 0;
}
