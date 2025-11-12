#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,score;
	std::cin>>n>>m;
	std::vector<int>v(n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		std::cin>>v[i];
	}
	score=v[1];
	std::sort(v.begin()+1,v.end(),[](int const&x,int const&y){return x>y;});
	for(int i=1;i<=n*m;i++)
	{
		if(v[i]==score)
		{
			auto c=(i%m==0?i/m:(i/m)+1);
			std::cout<<c<<' '<<(c%2==0?m-(i%m)+1:(i%m==0?m:i%m));
		}
	}
}
