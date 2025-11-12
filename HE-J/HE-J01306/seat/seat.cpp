#include<bits/stdc++.h>
using namespace std;
constexpr int N=11;
int n,m,a[N*N],val,rk;
int main(){
	freopen("seat.in","r",stdin),
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	val=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==val){
			rk=i;
			break;
		}
	int r=(rk+n-1)/n,c=(rk%n?rk%n:n);
	if(!(r&1))
		c=n-c+1;
	cout<<r<<' '<<c;
	return 0;
}
//Perhaps it's my last CSP-J, good luck!
