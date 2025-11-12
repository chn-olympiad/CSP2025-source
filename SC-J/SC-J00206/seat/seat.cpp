#include<bits/stdc++.h>
using namespace std;
int n,m;
struct cc{
	int s,n;
}a[205];
bool hel(cc l,cc r){
	return l.s>r.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].n=i;
	}
	sort(a+1,a+n*m+1,hel);
	for(int i=1;i<=n*m;i++){
		if(a[i].n==1){
			int h=1,l;
			h+=(i-1)/n;
			l=i%n;
			if(l==0) l=n;
			if(h%2==0) l=n-l+1;
			cout<<h<<" "<<l;
			return 0;
		}
	}
	return 0;
}