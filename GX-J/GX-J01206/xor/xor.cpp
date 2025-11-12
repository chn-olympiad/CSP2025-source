#include<iostream>
#include<vector>
#include<algorithm>

void solve1(std::vector<int>&a,int k)
{
	if(k==0)
	{
		int cnt=0;
		for(auto&i:a)
		{
			if(i==0)
			{
				cnt++;
			}
		}
		for(int i=1;i<a.size();i++)
		{
			if(a[i-1]==1&&a[i-1]==a[i])
			{
				cnt++;
				if(i<a.size()-1)
				{
					i++;
				}
			}
		}
		std::cout<<cnt;
		exit(0);
	}
	if(k==1)
	{
		std::cout<<std::count(a.begin(),a.end(),1);
		exit(0);
	}
}

void solve2(std::vector<int>&a,int k)
{
	std::cout<<std::count(a.begin(),a.end(),k);
	exit(0);
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	std::cin>>n>>k;
	std::vector<int>a(n);
	bool fAll1=true,fLessE1=true;
	for(auto&i:a)
	{
		std::cin>>i;
		if(i!=1)
		{
			fAll1=false;
		}
		if(i>1)
		{
			fLessE1=false;
		}
	}
	if(fAll1&&k==0)
	{
		std::cout<<(int)(((float)n)/2.0f+.5f);
	}
	else if(fLessE1)
	{
		solve1(a,k);
	}
	else
	{
		solve2(a,k);
	}
}
