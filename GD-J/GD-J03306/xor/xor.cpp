#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5;
int n,m,ans,sum,a[N],lgx[N];
void workx(){
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)sum++;
		if(a[i]==1&&a[i+1]==1)sum++,i++;
	}
	cout<<sum;
}
void worky(){
	for(int i=1;i<=n;i++)if(a[i]==1)sum++;
	cout<<sum;
}
bool check(int l,int r,int sum){
	if(sum==m)
	{
		ans=r;
		return 1;
	}
	if(l-1>ans)return check(l-1,r,sum^a[l-1]);
	if(r+1<=n&&a[r+1]<(1<<lgx[m])&&a[r+1]!=m)return check(l,r+1,sum^a[r+1]);
	return 0;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=2;i<N;i++)lgx[i]=lgx[i/2]+1;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==0)
	{
		workx();
		return 0;
	}
	if(m==1)
	{
		worky();
		return 0;
	}
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==m)ret++,ans=i;
		if(a[i]<(1<<lgx[m])||a[i]==m||i<=ans)continue;
		ret+=check(i,i,a[i]);
	} 
	cout<<ret;
	return 0;
}

