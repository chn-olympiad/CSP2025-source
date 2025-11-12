#include<Bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m;
struct node{
	int s,i;
}a[N];
bool cmp(node x,node y){
	return x.s>y.s;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int h=1,l=1,p=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].i==1) break;
		h+=p;
		if(h<=0||h>n){
			p*=-1;
			l++;
			h+=p;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
