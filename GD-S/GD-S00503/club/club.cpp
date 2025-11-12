#include<bits/stdc++.h>
using namespace std;
int T,t,n,a,b,c;
struct ma
{
	int peo,job,my;
	ma(int _peo,int _job,int _my)
	{
		peo=_peo;job=_job;my=_my;
	}
};
vector<ma> x;
bool cmp(ma a,ma b)
{
	return a.my>b.my; 
}

int solve()
{
	cin>>n;
	int t[3]={},ans;
	bool pe[n]={};
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		x.push_back(ma(i,0,a));x.push_back(ma(i,1,b));x.push_back(ma(i,2,c));
	}
	sort(x.begin(),x.end(),cmp);
	for(int i=0;i<x.size();i++)
	{
		if(!pe[x[i].peo]&&t[x[i].job]<=n/2)
		{
			pe[x[i].peo]=1;
			t[x[i].job]++;
			ans+=x[i].my;
		}
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cout<<solve()<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
