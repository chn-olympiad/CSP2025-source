#include<bits/stdc++.h>
using namespace std;
#define freop(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
#define ll long long
#define lb long double
#define re register
#define endl '\n'
#define pii pair<int,int>
#define fir first
#define sec second
const int N=101;
int n,m,nm,a[N],bas;

int main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	cout.tie(0);
	freop("seat");
//以上为初始化
//--------------------------------------
	cin >> n >> m,nm=n*m;
	for(int i = 1;i<=nm;++i) cin >> a[i];
	bas=a[1],sort(a+1,a+nm+1);
	int t=nm-(lower_bound(a+1,a+nm+1,bas)-a)+1;
	cout << (t+n-1)/n << ' ' << ((t+n-1)/n&1?(t-1)%n+1:n-(t-1)%n);
	return 0;
}
/*
2 2
98 99 100 97

2 2
99 100 97 98

*/

