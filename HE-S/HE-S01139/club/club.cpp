#include<bits/stdc++.h>
using namespace std;
//vector< pair<int,int> > a,b,c;
pair<int,int> a[114514],b[114514],c[114514];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first!=b.first)
		return a.first>b.first;
	return a.second>b.second;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int ans[n]={};
		bool bo[n]={};
		for(int i=0;i<n;i++)
		{
			ans[i]=-1;
			int x,y,z;
			cin>>x>>y>>z;
//			pair<int,int>a1,b1,c1;
//			a1.first=x,a1.second=i;
//			b1.first=y,b1.second=i;
//			c1.first=z,c1.second=i;
//			a.push_back(a1);
//			b.push_back(b1);
//			c.push_back(c1);
			a[i].first=x,a[i].second=i;
			b[i].first=y,b[i].second=i;
			c[i].first=z,c[i].second=i;
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		sort(c,c+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(ans[a[i].second]==-1)
			{
				ans[a[i].second]=a[i].first;
				bo[a[i].second]=true;
			}
			else
			{
				ans[a[i].second]=max(a[i].first,ans[a[i].second]);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(ans[b[i].second]==-1)
			{
				ans[b[i].second]=b[i].first;
				bo[b[i].second]=true;
			}
			else
			{
				ans[b[i].second]=max(b[i].first,ans[b[i].second]);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(ans[c[i].second]==-1)
			{
				ans[c[i].second]=c[i].first;
				bo[c[i].second]=true;
			}
			else
			{
				ans[c[i].second]=max(c[i].first,ans[c[i].second]);
			}
		}
		int ans1=0;
		for(int i=0;i<n;i++)
		{
			ans1+=ans[i];
		}
		cout<<ans1<<endl;
//		cout<<endl;
//		for(int i=0;i<n;i++)
//		{
//			cout<<a[i].first<<","<<a[i].second<<" "<<b[i].first<<","<<b[i].second<<" "<<c[i].first<<","<<c[i].second<<endl;
//		}
	}
	return 0;
}
//什么你说你看不懂我写了什么？
//没关系我也看不懂
//已经被提高组的一脚踹死了          
