#include<bits/stdc++.h>
using namespace std;

int n,m;
struct A{
	int n,i;
}a[105];

bool cmp(A a,A b){
	return a.n>b.n;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].n;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int d;
	for(int i=1;i<=n*m;i++) if(a[i].i==1){
		d=i;
		break;
	}
//	cout<<d<<endl;
	cout<<(d-1)/n+1<<' '<<((d-1)/n&1?n-(d-1)%n:(d-1)%n+1);
}
