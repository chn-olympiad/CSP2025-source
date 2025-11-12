#include<bits/stdc++.h>
using namespace std;
struct student{
	int f;
	bool is_r;
}a[105];
bool cmp(student a,student b) {
	return a.f>b.f;
}
int main() {
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p;
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++) {
		cin>>a[i].f;
		if (i==1) a[i].is_r = 1;
		else a[i].is_r = 0;
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i<=n*m;i++)
		if (a[i].is_r) {
			p = i;
			break;
		}
	if (!(((p-1)/n)%2)) {
		cout<<(p-1)/n+1<<' '<<(p-1)%n+1;
		return 0;
	} else {
		cout<<(p-1)/n+1<<' '<<n-((p-1)%n);
		return 0;
	}
}
