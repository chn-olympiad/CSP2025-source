#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

class ds
{
	int* data;
public:
	ds(int x):data(new int[x+1])
	{
		for(int i=1;i<=x;i++)
		{
			data[i]=i;
		}
	}
	~ds()
	{
		delete[] data;
	}
	
	int find(int x)
	{
		int root=x;
		while(root!=data[root])
		{
			root=data[root];
		}
		while(x!=root)
		{
			int p=data[x];
			data[x]=root;
			x=p;
		}
		return root;
	}
	bool merge(int x,int y)
	{
		if(find(x)!=find(y))
		{
			data[y]=x;
			return true;
		}
		return false;
	}
};

int kruskal(std::vector<std::tuple<int,int,int>>&g,int n)
{
	ds d(n);
	std::sort(g.begin(),g.end(),[](std::tuple<int,int,int>&x,std::tuple<int,int,int>&y){return std::get<2>(x)<std::get<2>(y);});
	int tot=0;
	for(int i=0;i<n-1;i++)
	{
		if(d.merge(std::get<0>(c),std::get<1>(c)))
		{
			tot+=std::get<2>(c);
		}
	}
	return tot;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	std::cin>>n>>m>>k;
	std::vector<std::tuple<int,int,int>>g(m);
	for(auto&i:g)
	{
		std::cin>>std::get<0>(i)>>std::get<1>(i)>>std::get<2>(i);
	}
	std::cout<<kruskal(g,n);
}
