#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
int n,k,s;
int a[500005],ans[100005];//ans[i]表示从1~i的最大答案 
vector <int>cnt[100005];//cnt[i][1~j]表示值为i的几个数所在位置 */

int n,k;
int a[500005],b[500005],ans[500005];
int main(int argc, char** argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		if(a[1]==1)
			cout<<n-1;
		else
			cout<<n;
	}
	else if(k==1)
	{
		if(a[1]==0)
			cout<<n-1;
		else
			cout<<n;
	}
	cout<<0;
	
	/*
	cin>>n>>k;
	map<int, vector<int>>mp;
	set<int>v;
	cnt[0].push_back(0);
	for(int i = 1;i<=n;i++)
	{
		 cin>>a[i];
		 if(i>1)
		 	a[i] = a[i]^a[i-1];//计算异或和 
		v.insert(a[i]);
		 if(!mp.count(a[i]))
		 	mp[a[i]].resize(100005);
		 mp[a[i]][i]++;//异或和的值为a[i],i位置有这么多个数 
		 cnt[a[i]].push_back(i);//计数器加1  
	}
	for(auto i:v)
	{
		for(int j = cnt[i].size()-2;j>=0;j--)
		{
			mp[i][cnt[i][j]]+=mp[i][cnt[i][j+1]];//后缀和，从i-cnt[a[i]]有这么多个数 
		}
	}
	for(int i = 1;i<=n;i++)
	{
		ans[i]+=ans[i-1];
		int d = k^a[i];//计算需要异或的数 
//		cout<<d<<" ";
		for(int j = 0;j<cnt[d].size();j++)//最大化价值同时防止重叠 
		{
			if(mp[d][cnt[d][j]]>ans[i-1] && cnt[d][j]<i)
			{
				cout<<cnt[d][j];
				ans[i-1] -= ans[cnt[d][j]];
				ans[i]+=mp[d][cnt[d][j]];
				break;
			}
		}
	}
	cout<<ans[n];*/
	return 0;
}
