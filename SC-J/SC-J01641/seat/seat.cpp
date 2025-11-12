#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
struct node{
	int val;
	bool f;
}a[N];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].val;
	a[1].f=1;
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;
	bool f=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].f){
			cout<<c<<' '<<r;
			return 0;
		}
		if(!f){
			r++;
			if(r>n)
				c++,r=n,f=1;
		}
		else{
			r--;
			if(!r)
				c++,r=1,f=0;
		}
	}
}