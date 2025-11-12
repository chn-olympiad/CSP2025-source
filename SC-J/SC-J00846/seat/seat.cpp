#include<bits/stdc++.h>
using namespace std;
struct st {
	int x;
	int c;
};
bool cmp(st a,st b) {
	return a.c>b.c;
}
st a[105];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].c;
		a[i].x=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int l,ansn,ansm;
	for(int i=1; i<=n*m; i++) {
		if(a[i].x==1) {
			l=i;
			break;
		}
	}
	ansn=l/m;
	if(l%m!=0) ansn++;
	l%=m;
	if(l==0) l=m;
	if(ansn%2==1) ansm=l;
	else ansm=m-l+1;
	cout<<ansn<<" "<<ansm;
	return 0;
}