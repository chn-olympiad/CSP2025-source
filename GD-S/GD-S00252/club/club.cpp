//t1 (rp<<=rp)<<=rp
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;
int n,ans,nxt[N];
struct Node{
	int val,id;
	bool operator<(const Node&b)const{
		return val>b.val;
	}
}a[N][5];
struct Student{
	int id,dis;
	bool operator<(const Student&b)const{
		return dis>b.dis;	
	}
};

signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		priority_queue<Student>q[5];
		memset(nxt,0,sizeof(nxt));
		ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j)
			{
				cin>>a[i][j].val;
				a[i][j].id=j;
			}
			nxt[i]=2;
			sort(a[i]+1,a[i]+3+1);
			int k=a[i][1].id;
			q[k].push( {i,a[i][1].val-a[i][2].val} );
//			cout<<i<<"在"<<k<<"组\n";
			while(q[k].size()>n/2)
			{
				auto tp=q[k].top();
				q[k].pop();
				int u=tp.id;
				int nt=nxt[u];
//				cout<<"nt="<<nt<<endl;
//				cout<<"check:"<<a[u][1].id<<" "<<a[u][2].id<<" "<<a[u][3].id<<endl;
				q[a[u][nt].id].push( {u,a[i][nt].val-a[i][nt+1].val} );
				k=a[u][nt].id;
				nxt[u]++;
//				cout<<u<<"被调到"<<k<<"组\n";
			}
		}
		for(int i=1;i<=3;++i)
		{
			while(!q[i].empty())
			{
				int tp=q[i].top().id;
				q[i].pop();
//				cout<<i<<":"<<tp<<"\n";
				for(int j=1;j<=3;++j)
					if(a[tp][j].id==i)ans+=a[tp][j].val;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
