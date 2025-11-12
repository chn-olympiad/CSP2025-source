#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){return x>y;}
int a[100005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int wei=0;
	for(int i=1;i<=n*m;i++){
		if(R==a[i]){wei=i;break;}
	}
	int t=ceil(wei*1.0/n),p=wei%n;
	if(p==0) p=n;
	cout<<t<<" ";
	if(t%2==1) cout<<p;
	else cout<<n-p+1;
	return 0;
}
//while(1) rp++; 