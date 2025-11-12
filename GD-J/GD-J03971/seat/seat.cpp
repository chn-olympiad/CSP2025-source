#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu {
	int score,id;
} a[10005];
bool cmp(stu x,stu y) {
	return x.score>y.score;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i].id==1) {
			int c=i/n;
			int d=i%n;
			if(d!=0)c++;
			else d=n;
			cout<<c<<" ";
			if(c%2==1) {
				cout<<d;
			} else {
				d=n-d+1;
				cout<<d;
			}
			return 0;
		}
	}
}
