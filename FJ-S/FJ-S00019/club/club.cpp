#include<bits/stdc++.h>
#define mkp make_pair
using namespace std;
#define int long long
const int N=1e5;
const int inf=0x7fffffff;
int n;
int ans;
int cnt[5];
int mid[5],mcha[5];
struct node
{
	int num,id;
}a[N+5][5];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >que1;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >que2;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >que3;
//priority_queue<pair<int,int> >que1;
//priority_queue<pair<int,int> >que2;
//priority_queue<pair<int,int> >que3;
bool cmp(node xx,node yy)
{
	return xx.num>yy.num; 
}
void psh(pair<int,int> xx,int which)
{
	if(which==1)
		que1.push(xx);
	else if(which==2)
		que2.push(xx);
	else
		que3.push(xx);
	return ;
}
pair<int,int> tp(int which)
{
	if(which==1)
		return que1.top();
	else if(which==2)
		return que2.top();
	else return que3.top();
}
void pp(int which)
{
	if(which==1)
		que1.pop();
	else if(which==2)
		que2.pop();
	else que3.pop();
	return ;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		while(!que1.empty())
			que1.pop();
		while(!que2.empty())
			que2.pop();
		while(!que3.empty())
			que3.pop();
		for(int i=1;i<=n;i++)
			cin>>a[i][1].num>>a[i][2].num>>a[i][3].num,a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
		for(int i=1;i<=n;i++)
			sort(a[i]+1,a[i]+3+1,cmp);
//		cout<<"\n";
//		for(int i=1;i<=n;i++)
//			cout<<a[i][1].num<<' '<<a[i][1].id<<" "<<a[i][2].num<<' '<<a[i][2].id<<" "<<a[i][3].num<<" "<<a[i][3].id<<"\n";
		for(int i=1;i<=n;i++)
		{
			int ncha=a[i][1].num-a[i][2].num;
			int now=a[i][1].id;
			if(cnt[now]<n/2)
			{
				cnt[now]++;
				ans+=a[i][1].num;
				psh(mkp(ncha,i),now);
			}
			else
			{
				pair<int,int>ft=tp(now);
//				cout<<ft.first<<" "<<ft.second<<"\n";
				if(ncha>ft.first)
				{
					pp(now);
					psh(mkp(ncha,i),now);
					psh(mkp(inf,i),a[ft.second][2].id);
					ans+=a[i][1].num;
					ans-=a[ft.second][1].num;
					ans+=a[ft.second][2].num;
				}
				else
					psh(mkp(inf,i),a[i][2].id),ans+=a[i][2].num;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

