#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=101;
int n,m,a[N],r,x=1,y=1;
bool f=1;
inline bool cmp(int a,int b){
	return a>b;
}
signed main(void){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i<=n*m;i++){
		if (a[i]==r){
			cout<<x<<" "<<y;
			return 0;
		}
		if ((y==n&&f)||(y==1&&!f)){
			f=!f;
			++x;
			continue;
		}
		if (f) ++y;
		else --y;
	}
}
