#include<algorithm>
#include<iostream>
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[1001],n,m,R,b;
	std::cin>>n>>m;
	b = n * m;
	for(int i = 1;i <= b;i++)
	{
		std::cin>>a[i];
	}
	R = a[1];
	std::sort(a + 1,a + 1 + b,cmp);
	int i = 1,j = 0,c = 0;
	while(1)
	{
		c++;
		if(i % 2 == 1){j ++;}
		if(i % 2 == 0){j --;}
		if(a[c] == R){std::cout<<i<<' '<<j;break;}
		if(j == n && i % 2 == 1){i ++;c++;}
		else if(j == 1 && i % 2 == 0){i ++;c++;}
		if(a[c] == R){std::cout<<i<<' '<<j;break;}
	}
	//std::cout<<std::endl<<R;
	return 0;
}
