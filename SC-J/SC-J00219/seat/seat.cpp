#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,now;
struct node{
	int x,y;
	bool operator <(const node &a){
		return x>a.x;
	}
}s[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>s[i].x,s[i].y=i;
	sort(s+1,s+1+n*m);now=1;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
			for(int j=1;j<=m;j++)
			{
				if(s[now].y==1)
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
				now++;
			}
		else
			for(int j=m;j>=1;j--){
				if(s[now].y==1){
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
				now++;
			}
	}
	return 0;
}