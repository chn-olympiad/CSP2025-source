#include<bits/stdc++.h>
using namespace std;
const int N=10005;
#define int long long
int n,m,a[N],t;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];	
	t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int w=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t) w=i;
	}
	int l=w/n,h=w%(n<<1);
	if(h%n!=0) l++;
	cout<<l<<' ';
	if(h>n) cout<<2*n-h+1;
	else cout<<h;
	return 0;
}
