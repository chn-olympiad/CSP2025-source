//Ren5Jie4Di4Ling5%
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

long long n,t;
const int dzy=1e5+10;
bool lkj,lk;
//set<long long> s;

struct ljhi//  刘嘉嗨() 
{
	long long j1;
	long long j2;
	long long j3;
}l[dzy];

int main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	
	ios::sync_with_stdio(false);
	
	lkj=true;
	lk=true;
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i].j1>>l[i].j2>>l[i].j3;
			if(l[i].j2!=0||l[i].j3!=0)
			    lkj=false;
			if(l[i].j3!=0)
			    lk=false; 
		}
		    
		
		//特殊性质我来啦 
		//特性A-12=5分 
		if(lkj)
		{
			long long k[100006],ans;
			for(int i=1;i<=n;i++)
				k[i]=l[i].j1;
			sort(k+1,k+n+1);
			for(int i=n;i>=n/2;i++)
			    ans+=k[i];
			cout<<ans<<endl;
		}
		//特性B-9.13.14=15分 得不全，脑子转不开+困 
		if(lk==true&&lkj==false)
		{
			long long k[100006],j[100006],ans;
			for(int i=1;i<=n;i++)
			{
				if(l[i].j1>=l[i].j2)
				    ans+=l[i].j1;
				if(l[i].j1<l[i].j2)
				    ans+=l[i].j2;
			}
			cout<<ans<<endl; 
		}
		
		//特性C-15.16=10分
		//完全不会hhh 
	}
	return 0;
} 
