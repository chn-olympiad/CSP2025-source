#include<bits/stdc++.h>
#define ll long long
#define str string
#define endl '\n'
using namespace std;
int a[105],pos[105];
bool cmp(int l,int r) {
	return l>r;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pos[i]=i;
	for(int i=n+1;i<=2*n;i++) pos[i]=2*n-i+1;
	int cur=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) {
		if (a[i]==cur) {
			cout<<(i+n-1)/n<<' '<<pos[i%(n*2)];
			break;
		} 
	}
	return 0;
}