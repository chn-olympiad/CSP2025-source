#include<bits/stdc++.h>
using namespace std;
int n,m,r,c;
struct Stu{
	int a,id;
}s[105];
bool cmp(const Stu &a,const Stu &b) {
	return a.a>b.a;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) {
		cin>>s[i].a;
		s[i].id=i;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int rp=1;rp<=n*m;rp++) {
		if(c%2) {
			r++;
			if(r>n) r=n,c++;
		}
		else {
			r--;
			if(r<1) r=1,c++;
		}
		if(s[rp].id==1) {
			cout<<c<<' '<<r;
			return 0;
		}
	}
	return 0;
}
