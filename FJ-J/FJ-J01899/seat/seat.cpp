#include<bits/stdc++.h>
using namespace std;
int n,m;
struct s{
	int s,t;
}a[100005];
bool cmp(s aa,s bb){
	return aa.s>bb.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].t=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int p;
	for(int i=1;i<=n*m;i++){
		if(a[i].t==1){
			p=i;
			break;
		}
	}
	int q=0;
	if(p%n==0)q=p/n;
	else q=p/n+1;
	int x=p%(2*n);
	if(x>n){
		cout<<q<<" "<<n-(x-m)+1;
	}else{
		cout<<q<<" "<<x;
	}
}
