#include<bits/stdc++.h>
using namespace std;
long long n,T,maxx[1000010],sec[1000010],minn[1000010];
struct node{
	long long val,id;
}a[1000010][4],tp[110];
long long cmp(node x,node y)
{
	return x.val>y.val;
}
priority_queue<pair<long long,long long> >q[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>T;
	while(T--)
	{
		long long sum[4]={0,0,0,0},ans=0;
		for(int i=1;i<=3;i++)
		{
			while(!q[i].empty())
			{
				q[i].pop();
			}
		}
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1].val>>a[i][2].val>>a[i][3].val;
			a[i][1].id=1;a[i][2].id=2;a[i][3].id=3;
			tp[1]=a[i][1];tp[2]=a[i][2];tp[3]=a[i][3];
			sort(tp+1,tp+4,cmp);
			maxx[i]=tp[1].id;sec[i]=tp[2].id;minn[i]=tp[3].id;
		}
//		cout<<a[1][maxx[1]].val<<' '<<a[1][sec[1]].val<<' '<<a[2][maxx[2]].val<<'\n';
		for(int i=1;i<=n;i++)
		{
			if(sum[maxx[i]]<n/2)
			{
				sum[maxx[i]]++;
				ans+=a[i][maxx[i]].val;
				q[maxx[i]].push({a[i][sec[i]].val-a[i][maxx[i]].val,i});
			}
			else
			{
				long long val=q[maxx[i]].top().first;
				if(a[i][maxx[i]].val+val>a[i][sec[i]].val)
				{
					q[maxx[i]].pop();
					ans+=(a[i][maxx[i]].val+val);
					q[maxx[i]].push({a[i][sec[i]].val-a[i][maxx[i]].val,i});
				}
				else
				{
					sum[sec[i]]++;
					ans+=a[i][sec[i]].val;
					q[sec[i]].push({a[i][minn[i]].val-a[i][sec[i]].val,i});
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
QWQ
jiangly佑我
显然，当一个部门已经满员时，如果要排人肯定会去第二高的那个
且不可能要去的那个部门也满员 
T1用时一个小时叫我最菜蒟蒻
*/
