#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1000;
struct node{
	int val,id;
}a[N];
bool cmp(node x,node y){return x.val>y.val;}
int n,m,num,c,r;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			num=i;
			break;
		}
	}
	if(num%n==0)c=num/n;
	else c=num/n+1;
	if(c&1){
		if(num%n==0)r=n;
		else r=num%n;
	}
	else{
		if(num%n==0)r=1;
		else r=n-num%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
