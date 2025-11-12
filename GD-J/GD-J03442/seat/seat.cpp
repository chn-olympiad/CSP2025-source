#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int s=a[1],now;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)if(a[i]==s)now=i;
	int ans=now/n+(now%n==0?0:1);
	now-=(ans-1)*n;
	cout<<ans<<" "<<((ans%2==0)?n-now+1:now);
	return 0;
}
//freopen luogu uid:695750 
//si nian ji dao chu san yi lai di yi ci guo j zu chu sai QWQ  
