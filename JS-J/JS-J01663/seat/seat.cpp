#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nod{
	int sum,id;
}a[110];
int n,m,x=1,y=1;
bool cmp(nod p,nod q){
	return p.sum>q.sum;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].sum;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i].id==1){
			cout<<x<<" "<<((x/n)%2?n-y+1:y)<<endl;
			break;
		}
		y++;
		if(y>n){
			y=1;
			x++;
		}
	}
	return 0;
}
