#include<iostream>
using namespace std;
const int N=1e5+5;
int t,n,ans,w[N][3];
void work(int a,int b, int c,int h,int ma)
{
	if (h>n)
	{
		ans=max(ans,ma);
		return ;
	}
	if (a<n/2){
		work(a+1,b,c,h+1,ma+w[h][0]);
	}
	if (b<n/2){
		work(a,b+1,c,h+1,ma+w[h][1]);
	}
	if (c<n/2){
		work(a,b,c+1,h+1,ma+w[h][2]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>w[i][0]>>w[i][1]>>w[i][2];
		}
		work(0,0,0,1,0);
		cout<<ans<<'\n';
	}
	return 0;
 } 
