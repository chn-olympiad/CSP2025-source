#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int n,m;
struct node{
	int id;
	int val;
};
node a[N];
bool cmp(node a,node b){
	return a.val>b.val;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int rk;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1) rk=i;
	}
	int c,tmp;
	if(rk%m==0) c=rk/m,tmp=m;
	else c=rk/m+1,tmp=rk-(c-1)*m;
	int r;
	if(c%2==1) r=tmp;
	else r=n-tmp+1;
	cout<<c<<' '<<r;
	return 0;
}
