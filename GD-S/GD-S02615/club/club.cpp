#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5;
struct node{
	int arr[4];//1,2,3部门的满意程度
	int maa,mab,mac;//最高的是哪个部门，中的，低的 
};
node G[N];
void init(int i)
{
	pair<int,int>sa,sb,sc;
	sa.first=G[i].arr[1];
	sb.first=G[i].arr[2];
	sc.first=G[i].arr[3];
	sa.second=1;sb.second=2;sc.second=3;
	if(sb.first<sc.first)swap(sb,sc);
	if(sa.first<sb.first)swap(sa,sb);
	if(sa.first<sc.first)swap(sa,sc);
	if(sb.first<sc.first)swap(sb,sc);
	G[i].maa=sa.second,G[i].mab=sb.second,G[i].mac=sc.second;
}
bool cmp2(int stu1,int stu2)
{
	return (G[stu1].arr[G[stu1].maa]-G[stu1].arr[G[stu1].mab])>(G[stu2].arr[G[stu2].maa]-G[stu2].arr[G[stu2].mab]);
}
void solve()
{
	int n;cin>>n;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>G[i].arr[1]>>G[i].arr[2]>>G[i].arr[3];
		init(i); 
		res+=G[i].arr[G[i].maa];
	}
	vector<int>q1,q2,q3;
	
	for(int i=1;i<=n;i++)
	{
		if(G[i].maa==1)q1.push_back(i);
		if(G[i].maa==2)q2.push_back(i);
		if(G[i].maa==3)q3.push_back(i);
		
	}
	sort(q1.begin(),q1.end(),cmp2);
	sort(q2.begin(),q2.end(),cmp2);
	sort(q3.begin(),q3.end(),cmp2);
//	cout<<"@@@#!@#@!#\n";
//	for(auto tmp:q1)cout<<tmp<<" ";cout<<endl;
//	for(auto tmp:q2)cout<<tmp<<" ";cout<<endl;
//	for(auto tmp:q3)cout<<tmp<<" ";cout<<endl;
//	cout<<"-----------------\n";
//	for(int i=1;i<=n;i++)
//	{
//		cout<<G[i].maa<<" "<<G[i].mab<<" "<<G[i].mac<<endl;
//	}
//	cout<<"@@@#!@#@!#\n";
//	cout<<res;
	while(q1.size()>n/2)//第一社团超人
	{
		int ss=q1.back();q1.pop_back();
//		cout<<"!!!!"<<ss<<" "<<G[ss].arr[G[ss].maa]<<" "<<G[ss].arr[G[ss].mab]<<"!!!!!\n";
		res-=(G[ss].arr[G[ss].maa]-G[ss].arr[G[ss].mab]);
	 } 
	 while(q2.size()>n/2)//第一社团超人
	{
		int ss=q2.back();q2.pop_back();
//		cout<<"!!!!"<<ss<<" "<<G[ss].arr[G[ss].maa]<<" "<<G[ss].arr[G[ss].mab]<<"!!!!!\n";
		res-=(G[ss].arr[G[ss].maa]-G[ss].arr[G[ss].mab]);
	 } 
	 while(q3.size()>n/2)//第一社团超人
	{
		int ss=q3.back();q3.pop_back();
//		cout<<"!!!!"<<ss<<" "<<G[ss].arr[G[ss].maa]<<" "<<G[ss].arr[G[ss].mab]<<"!!!!!\n";
		res-=(G[ss].arr[G[ss].maa]-G[ss].arr[G[ss].mab]);
	 } 
	 cout<<res<<endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)
		solve();
}
/*
147325
125440
152929
150176
158541

3
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
*/
