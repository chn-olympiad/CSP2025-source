#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
struct Node
{
	int x;//满意度
	int num;//属于第num个部门
	int idx;//第idx个新成员 
}a[3*maxn]; 
bool cmp(Node a,Node b)
{
	return a.x>b.x;
}
int cnt[5];//记录选择第i个部门的人的数量 
bool vis[maxn];//第i个人是否已经选择完了 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int tot=0;
		if(n==2)
		{
			int p[5];
			int q[5];
			cin>>p[1]>>p[2]>>p[3];
			cin>>q[1]>>q[2]>>q[3];
			cout<<max(p[1]+q[2],max(p[1]+q[3],max(p[2]+q[1],max(p[2]+q[3],max(p[3]+q[1],p[3]+q[2])))))<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[++tot].x;
			a[tot].idx=i;
			a[tot].num=1;
			cin>>a[++tot].x;
			a[tot].idx=i;
			a[tot].num=2;
			cin>>a[++tot].x;
			a[tot].idx=i;
			a[tot].num=3; 
			
			vis[i]=0; 
		} 
		sort(a+1,a+tot+1,cmp);
		cnt[1]=cnt[2]=cnt[3]=0;
		
		int sum=0;
		for(int i=1;i<=tot;i++)
		{
//			cout<<a[i].idx<<' '<<vis[a[i].idx]<<endl;
			if(cnt[a[i].num]+1>n/2||vis[a[i].idx]==1)
			{
//				cout<<a[i].idx<<' '<<a[i].x<<endl;
				continue;
			}
			cnt[a[i].num]++;
			sum+=a[i].x;
			vis[a[i].idx]=1;
//			cout<<a[i].idx<<' '<<a[i].x<<endl;
		}
//		cout<<a[4].x<<endl;
		cout<<sum<<endl;
	}
	return 0;
 } 
 /*
1
2
10 9 8
4 0 0
 */
