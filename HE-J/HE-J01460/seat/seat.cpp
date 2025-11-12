#include<bits./stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
	int id,x;
}a[1010];
bool cmp(node a,node b){
	return a.x>b.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			int l;
			if(i%n==0)l=i/n;
			else l=i/n+1;
			if(l%2==0){
				if(i%n!=0)cout<<l<<' '<<n-i%n+1;
				else cout<<l<<' '<<1;
				break;
			}else{
				if(i%n!=0)cout<<l<<' '<<i%n;
				else cout<<l<<' '<<n;
				break;
			}
		}
	}
	return 0;
}
