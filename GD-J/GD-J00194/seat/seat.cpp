#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xm,tot,cnt=0;
	cin>>n>>m>>xm;
	a[1]=xm;
	tot=n*m;
	for(int i=2;i<=tot;i++)cin>>a[i];
	sort(a+1,a+tot+1);
	int idx=tot-(lower_bound(a+1,a+tot+1,xm)-a)+1;
	while(idx>n){
		idx-=n;
		cnt++;
	}
	if(cnt%2==0)cout<<cnt+1<<' '<<idx;
	else cout<<cnt+1<<' '<<n-idx+1;
	return 0;
}
