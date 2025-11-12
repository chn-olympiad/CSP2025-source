#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=100+10;
int n,m,a[maxn*maxn];
int id,s;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			id=i;
			break;
		}
	}
	int c,r;
	if(id%n==0) r=id/n;
	else r=id/n+1;
	int sy=id-(r-1)*n;
	if(r%2==1) c=sy;	
	else c=n-sy+1;
	cout<<r<<" "<<c;
	return 0;
}