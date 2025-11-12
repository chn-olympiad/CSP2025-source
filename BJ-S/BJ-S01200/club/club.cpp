#include <iostream>
#include <queue>
using namespace std;
int a[100002][4];
priority_queue<pair<int,int>> q[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		while (q[1].size()) q[1].pop();
		while (q[2].size()) q[2].pop();
		while (q[3].size()) q[3].pop();
		long long ans=0;
		int n;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for (int i=1;i<=n;i++)
		{
			if (a[i][1]>a[i][2] && a[i][1]>a[i][3])
			{
//						cout<<ans<<"+="<<a[i][1]<<endl;
				ans+=a[i][1];
				q[1].push(make_pair(-(a[i][1]-max(a[i][2],a[i][3])),i));
				if (q[1].size()>n/2)
				{
					auto _now=q[1].top();
					int now=_now.second;
					if (a[now][2]>a[now][3]){
						q[2].push(make_pair(-(a[now][2]-a[now][3]),now));
//						cout<<ans<<"+="<<a[now][2]<<endl;
						ans+=a[now][2];
					}
					else{
						q[3].push(make_pair(-(a[now][3]-a[now][2]),now));
//						cout<<ans<<"+="<<a[now][3]<<endl;
						ans+=a[now][3];
						
					}
//						cout<<ans<<"-="<<a[now][1]<<endl;
					ans-=a[now][1];
					q[1].pop();
				}
			}
			if (a[i][2]>a[i][3] && a[i][1]<a[i][2])
			{
//						cout<<ans<<"+="<<a[i][2]<<endl;
				ans+=a[i][2];
				q[2].push(make_pair(-(a[i][2]-max(a[i][1],a[i][3])),i));
				if (q[2].size()>n/2)
				{
//					cout<<"full";
					auto _now=q[2].top();
					int now=_now.second;
					if (a[now][1]>a[now][3]){
						q[1].push(make_pair(-(a[now][1]-a[now][3]),now));
//						cout<<ans<<"+="<<a[now][1]<<endl;
						ans+=a[now][1];
					}
					else{
						q[3].push(make_pair(-(a[now][3]-a[now][1]),now));
//						cout<<ans<<"+="<<a[now][3]<<endl;
						ans+=a[now][3];
					}
//						cout<<ans<<"-="<<a[now][2]<<endl;
					q[2].pop();
					ans-=a[now][2];
				}
			}
			if (a[i][3]>a[i][2] && a[i][1]<a[i][3])
			{
//						cout<<ans<<"+="<<a[i][3]<<endl;
				ans+=a[i][3];
				q[3].push(make_pair(-(a[i][3]-max(a[i][2],a[i][1])),i));
				if (q[3].size()>n/2)
				{
					auto _now=q[3].top();
					int now=_now.second;
					if (a[now][1]>a[now][2]){
						q[1].push(make_pair(-(a[now][1]-a[now][2]),now));
						ans+=a[now][1];
//						cout<<ans<<"+="<<a[now][1]<<endl;
					}
					else{
						q[2].push(make_pair(-(a[now][2]-a[now][1]),now));
						ans+=a[now][2];
//						cout<<ans<<"+="<<a[now][2]<<endl;
					}

					q[3].pop();
//						cout<<ans<<"-="<<a[now][3]<<endl;
					ans-=a[now][3];
				}
			}
		}
		cout<<ans<<endl;
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/