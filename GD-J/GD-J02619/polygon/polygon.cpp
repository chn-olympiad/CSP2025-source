#include<iostream>
#include<map>
#include<algorithm>
#define P 998244353
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long ans = 0;
	map<int,int> total;
	int n;
	cin>>n;
	int w[n+1];
	for(int i = 1;i <= n;++i)
	cin>>w[i];
	sort(w+1,w+n+1);
	for(int i = 1;i <= n;++i)
	{
		for(auto j = total.begin();j != total.end();++j)
		{
			if(j->first > w[i])
			{
				ans+=j->second;
				ans%=P;
			}
		}
		map<int,int> temp = total;
		for(auto j = temp.begin();j != temp.end();++j)
		{
			if(!total.count(j->first+w[i]))total[j->first+w[i]] = j->second;
			else{total[j->first+w[i]]+=j->second;total[j->first+w[i]]%=P;}
		}
		if(!total.count(w[i]))total[w[i]] = 1;
		else ++total[w[i]];
	}
	cout<<ans;
}
