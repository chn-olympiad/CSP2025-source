#include<bits/stdc++.h>
#define ll long long
#define str string
#define I return
#define Will 0
#define AK ;
using namespace std;
void setup()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
ll n,a[5005],ans;
void dfs(ll pos,ll tot,ll maxx,ll cnt)
{
	//cout<<tot<<" "<<maxx<<endl;
	if(cnt>=3&&tot>maxx*2)ans++;
	if(pos==n)return;
	for(int i=pos+1;i<=n;i++)
		dfs(i,tot+a[i],max(maxx,a[i]),cnt+1);
}
int main()
{
 	setup();
 	cin>>n;
 	for(int i=1;i<=n;i++)
 		cin>>a[i];
 	sort(a+1,a+1+n); 
 	for(int i=1;i<=n;i++)
 		dfs(i,a[i],a[i],1);	
 	cout<<ans;
	I Will AK
}

