#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e4;
int arr[N];
int G[N][N];//预处理i到j区间的所有异或值 
struct node{
	int l,r;
}; 
bool cmp(node a,node b)
{
	if((a.r-a.l)==(b.r-b.l))return a.l>b.l;
	else return (a.r-a.l)<(b.r-b.l) ;
}
vector<node>vect;
bool xx[N];
bool check(node cc)
{
	for(int i=cc.l;i<=cc.r;i++)
	{
		if(xx[i]==1)return 0;
	}
	return 1;
}
void add(node cc)
{
	for(int i=cc.l;i<=cc.r;i++)
	{
		xx[i]=1;
	}
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>arr[i];
	for(int i=1;i<=n;i++)
	{
		G[i][i]=arr[i];	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			G[i][j]=(G[i][j-1]^arr[j]);
		}
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<G[i][j]<<" ";
//		cout<<endl;
//	}
		
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(G[i][j]==k)
				vect.push_back(node{i,j});
	sort(vect.begin(),vect.end(),cmp);
	
//	for(auto tmp:vect)cout<<tmp.l<<" "<<tmp.r<<endl;
	
	int res=0;
	for(auto tmp:vect)
	{
		if(check(tmp)==1)//可以塞下这个区间
		{
//			printf("可以塞下这个%d %d\n",tmp.l,tmp.r);
			res++;
			add(tmp);//加入这个区间 
//			for(int i=1;i<=n;i++)cout<<xx[i];
//			cout<<endl;
		} 
//		else printf("不选择 %d %d\n",tmp.l,tmp.r);
	}
	cout<<res;
}
