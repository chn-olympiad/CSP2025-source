#include<bits/stdc++.h>
using namespace std;
const int N=200;
int a[N];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,t1,t2,t3,l,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		r=a[1];
	}
	sort(a+1,a+n*m+1);
	r=lower_bound(a+1,a+n*m+1,r)-a;
	r=n*m-r+1;
	t1=r%(n*2);
	t2=r/(n*2);
	l=2*t2;
	if(t1){
		l++;
		if(t1>n){
			l++;
			t3=t1-m;
			h=m-t3+1;
		}
		else h=t1;
		cout<<l<<' '<<h;
	}
	else{
		cout<<l<<' '<<n;
	}
	return 0;
}

