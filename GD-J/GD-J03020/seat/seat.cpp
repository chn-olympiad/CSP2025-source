#include<bits/stdc++.h>
using namespace std;

int n, m;

struct ls
{
	
	int a;
	int we;
	
};

vector<ls> mar;

bool cmp(ls A, ls B)
{

	return A.a>B.a;
	
}

int main()
{
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin>>n>>m;
	
	ls ci;
	
	for(int i=1;i<=n*m;i++)
	{
		
		cin>>ci.a;
		ci.we=i;
		mar.push_back(ci);
		
	}
	
	sort(mar.begin(), mar.end(), cmp);
	
	int cnt=0;
	
	for(auto pa:mar)
	{
		
		cnt++;
		
		if(pa.we==1)
		{
			
			break;
			
		}
		
	}
	
	int ans1, ans2;
	ans1=cnt/n;
	if(cnt%n!=0)
	{
		
		ans1++;
		
	}
	
	if(ans1%2!=0)
	{
		
		if(cnt%n==0)
		{
			
			ans2=n;
			
		}
		else
		{
			
			ans2=cnt%n;
			
		}
		
	}
	else
	{
		
		if(cnt%n==0)
		{
			
			ans2=1;
			
		}
		else
		{
			
			ans2=n-(cnt%n)+1;
			
		}
		
	}
	
	cout<<ans1<<" "<<ans2;
	
	return 0;
	
}
