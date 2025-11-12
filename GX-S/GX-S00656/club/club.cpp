#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>

struct arr_t
{
	int a=0,b=0,c=0;
	int mx=0,mn=0,md=0;
	void apply()
	{
		max();
		min();
		mid();
	}
	int max()
	{
		mx=std::max({a,b,c});
		if(mx==a)
		{
			return 0;
		}
		if(mx==b)
		{
			return 1;
		}
		if(mx==c)
		{
			return 2;
		}
		return -1;
	}
	int mid()
	{
		int arr[3]={a,b,c};
		std::sort(arr,arr+3);
		md=arr[1];
		if(md==a)
		{
			return 0;
		}
		if(md==b)
		{
			return 1;
		}
		if(md==c)
		{
			return 2;
		}
		return -1;
	}
	int min()
	{
		mn=std::min({a,b,c});
		if(mn==a)
		{
			return 0;
		}
		if(mn==b)
		{
			return 1;
		}
		if(mn==c)
		{
			return 2;
		}
		return -1;
	}
	int& operator[](size_t n)
	{
		if(n==0)
		{
			return a;
		}
		if(n==1)
		{
			return b;
		}
		if(n==2)
		{
			return c;
		}
		throw std::out_of_range("oor");
	}
};

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	std::cin>>t;
	while(t--)
	{
		int n,maxsum=0;
		std::cin>>n;
		std::vector<arr_t>a(n);
		arr_t cnt;
		for(auto&i:a)
		{
			std::cin>>i.a>>i.b>>i.c;
			i.apply();
			cnt[i.max()]++;
			maxsum+=i.mx;
		}
		cnt.apply();
		if(n==2)
		{
			if(cnt.mx==2)
			{
				a[0].apply();
				a[1].apply();
				if(maxsum-a[0].mx+a[0].md>maxsum-a[0].mx+a[0].md)
				{
					std::cout<<maxsum-a[0].mx+a[0].md<<'\n';
				}
				else
				{
					std::cout<<maxsum-a[0].mx+a[0].md<<'\n';
				}
			}
			else
			{
				std::cout<<maxsum<<'\n';
			}
			continue;
		}
		int m=cnt.max();
		if(cnt.mx>n/2)
		{
			std::sort(a.begin(),a.end(),[&m](arr_t&a,arr_t&b){return a[m]<b[m];});
			for(int i=0,j=n-1;i<=n/2&&j>=n/2;i++,j--)
			{
				if(maxsum-a[i].mx+a[i].md>maxsum-a[j].mx+a[j].md)
				{
					maxsum-=a[i].mx;
					maxsum+=a[i].md;
				}
				else
				{
					maxsum-=a[j].mx;
					maxsum+=a[j].md;
				}
			}
			std::cout<<maxsum<<'\n';
		}
		else
		{
			std::cout<<maxsum<<'\n';
		}
	}
}
