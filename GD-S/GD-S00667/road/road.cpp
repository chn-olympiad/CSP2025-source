#include<iostream>
#include<vector>

using namespace std;

struct road
{
	int c1;
	int c2;
	int cost;
	
	road()
	{
		c1=2000000000;
		c2=2000000000;
		cost=2000000000;
	}
	
	bool operator<(const road& rd)
	{
		return cost<rd.cost;
	}
	
	bool operator>(const road& rd)
	{
		return cost>rd.cost;
	}
	
	bool operator==(const road& rd)
	{
		if(c1==rd.c1&&c2==rd.c2&&cost==rd.cost)
		return true;
	}
};

struct village
{
	int cost;
	vector<int> costtocity;
};

template<typename T>
bool myfind(const vector<T>& v,const T& fd)
{
	bool result=false;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==fd)
		{
			result=true;
		}
	}
	return result;
}

class mymap
{
	public:
		vector<road> roads;
		vector<int> pts;
		
		bool testadd(road rd)
		{
			static road buff;
			if(!myfind(roads,rd))
			{
				for(int i=0;i<pts.size();i++)
				{
					if((myfind(pts,rd.c1)&&!myfind(pts,rd.c2))||(!myfind(pts,rd.c1)&&myfind(pts,rd.c2)))
					{
						
					}
				}
			}
		}
};

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	
	cin>>n>>m>>k;
	
	vector<road> roads(m);
	for(int i=0;i<m;i++)
	{
		cin>>roads[i].c1>>roads[i].c2>>roads[i].cost;
	}
	
	vector<village> villages(k);
	for(int i=0;i<k;i++)
	{
		cin>>villages[i].cost;
		villages[i].costtocity=vector<int>(n);
		for(int j=0;j<n;j++)
		{
			cin>>villages[i].costtocity[j];
		}
	}
	
	//¥¶¿Ì 
	
	
	return 0;
}
