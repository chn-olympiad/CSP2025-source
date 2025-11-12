#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20;
int s[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	h=s[1];
	sort(s+1,s+n*m+1,[](int x,int y){return x>y;});
	int r=0,c=1,d=1;
	for(int i=1;i<=n*m;i++) {
		r+=d;
		if(r>n) {
			r=n;
			c++;
			d=-1;
		}else if(r<1) {
			r=1;
			c++;
			d=1;
		}
		if(s[i]==h) {
			cout<<c<<' '<<r;
			return 0;
		}
	}
	
	return 0;
}