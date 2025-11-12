#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int cnt=1;
	for(int i=2;i<=n*m;i++)cnt+=(a[i]>a[1]);
	int i=1;
	while(cnt>n)cnt-=n,i++;
	if(i&1)cout<<i<<' '<<cnt;
	else cout<<i<<' '<<n-cnt+1;
	return 0;
}
