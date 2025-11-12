#include<bits/stdc++.h>
#define ll long long

using namespace std;

/*
01
10
11 

010
100
110
^

*/ 

//25000000

ll a[5010],n,k,lon=0;
bool is=false,used[5010];
vector<vector<ll>> ans;
vector<ll> v;

void f(ll index,ll val)
{
	if(val==k)
	{
		is=true;
		ans.push_back(v);	
	} 
	else
	{
		for(ll i=index;i<=n;i++)
		{
			if(used[i]==false)
			{
				v.push_back(a[i]);
				f(i+1,val^a[i]);
				v.pop_back();
				if(is)
				{
					used[i]=true;
					is=false;
					continue;
				}
			}
		}
	}
}

int main()
{
	ifstream fin("xor.in");
	ofstream fout("xor.out");
	
	//printf("%d",1^2);
	fin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		fin>>a[i];
		if(a[i]==k)
		{
			lon++;	
			used[i]=true;
		} 
		else used[i]=false;	
	} 
	
	for(int i=1;i<=n;i++)
		f(i,a[i]);
	
	fout<<ans.size()+lon;
		
	fin.close();
	fout.close();
	return 0;
}
