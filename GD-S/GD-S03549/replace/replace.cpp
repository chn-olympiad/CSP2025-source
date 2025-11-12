#include<iostream>
#include<vector>
#include<string> 
using namespace std;
//16:47;恩大概就是按照规律替换其中一个子串后如果和目标一样就ans++吧，正解想都不用想了直接来暴力
int n,q;
vector< pair<string,string> >book;
string now,later;
int main()
{
	book.reserve(200005);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	if(n*q>=1000000){
		while(q--)cout<<0<<endl;
		exit(0);
	}
	pair<string,string>a;
	for(int i=1;i<=n;i++)
	{
		cin>>a.first>>a.second;
		book.push_back(a);	
	}
	//滑动窗口遍历所有question的子序列，看是否能够修改，若能则修改，然后再判断是否和所求一致，若一致则ans++ 
	while(q--)
	{
		cin>>now>>later;
		int ans=0;
		string ceshi,tryto;
		for(int i=1;i<=now.size();i++)
		{
			for(int j=0;j+i-1<now.size();j++){
				ceshi=now.substr(j,i);
				for(int k=0;k<book.size();k++)
				{
					//待会考虑性质B
					if(ceshi==book[k].first)
					{
						tryto=now.substr(0,j)+book[k].second+now.substr(i+j);
						if(tryto==later)ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
