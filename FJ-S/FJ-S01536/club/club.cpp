/*
1.开freopen
2.for循环
3.倒序遍历i--
4.开ll
5.数组溢出
6.初始化
7.删debug语句
8.n*m数组遍历
//*/
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],st;
int _max(int i,int x,int y)
{
	int m=max(a[i][x],a[i][y]);
	if(m==a[i][x])return x;
	else return y;
}
pair<int,int> change(int i)
{
	int m=max(max(a[i][1],a[i][2]),a[i][3]);
	if(m==a[i][1])return {m-max(a[i][2],a[i][3]),_max(i,2,3)};
	else if(m==a[i][2])return {m-max(a[i][1],a[i][3]),_max(i,1,3)};
	else return {m-max(a[i][2],a[i][1]),_max(i,2,1)};
}
bool cmp(int x,int y)
{
	return change(x).first>change(y).first;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int>v[5];
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int m=max(max(a[i][1],a[i][2]),a[i][3]);
			sum+=m;
			if(m==a[i][1])v[1].push_back(i);
			else if(m==a[i][2])v[2].push_back(i);
			else v[3].push_back(i);
		}
		if(v[1].size()>n/2)st=1;
		else if(v[2].size()>n/2)st=2;
		else if(v[3].size()>n/2)st=3;
		else
		{
			cout<<sum<<endl;continue;
		}
		/*
		for(int i=1;i<=3;i++)
		{
			for(int j=0;j<v[i].size();j++)
				cout<<v[i][j]<<" ";
			cout<<endl;
		}
		//*/
		sort(v[st].begin(),v[st].end(),cmp);
		/*
		for(int i=1;i<=3;i++)
		{
			for(int j=0;j<v[i].size();j++)
				cout<<v[i][j]<<" ";
			cout<<endl;
		}
		//*/
		for(int i=v[st].size()-1;v[st].size()>n/2;i--)
		{
			int u=v[st][i];
			/*
			cout<<change(u).second<<endl;
			//*/
			v[change(u).second].push_back(u);
			v[st].pop_back();
		}
		/*
		for(int i=1;i<=3;i++)
		{
			for(int j=0;j<v[i].size();j++)
				cout<<v[i][j]<<" ";
			cout<<endl;
		}
		//*/
		int ans=0;
		for(int i=1;i<=3;i++)
			for(int j=0;j<v[i].size();j++)
				ans+=a[v[i][j]][i];
		cout<<ans<<endl;
	}
	return 0;
}

