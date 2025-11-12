#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct as{
	int val,id;
}d[105];
bool cmp(as a,as b){
	return a.val>b.val;
} 
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>d[i].val;
		d[i].id=i;
	}
	sort(d+1,d+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(d[i].id==1) k=i;
	int t=k/n;
	if(k%n==0){
		cout<<t<<" "<<(t&1?n:1);
		return 0;
	}
	k-=t*n;
	if(t&1) cout<<t+1<<" "<<n-k+1;
	else cout<<t+1<<" "<<k;
}
