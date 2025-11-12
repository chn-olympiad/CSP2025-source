#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,ans;
struct num {
	int score;
	int id;
} a[N];
bool cmp(num x,num y) {
	return x.score>y.score;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++) {
		if(a[i].id==1) {
			ans=i;
			break;
		}
	}
	int hang,lie;
	lie=ceil(ans*1.0/n);
	if(lie%2==1) {
		hang=ans%n;
		if(hang==0)hang=n;
	} else {
		if(ans%n==0)hang=n;
		else hang=n-ans%n+1;
	}
	cout<<lie<<" "<<hang;
	return 0;

}

