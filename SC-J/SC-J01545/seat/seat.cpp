#include<bits/stdc++.h>
#define I ios_base::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
#define int long long 
using namespace std;
const int maxn=1001;
int a[maxn],m,n,p;
int quzheng(int h){
	int ansl;
	double l=(h*1.0/n*1.0);
	if(l==h/n)ansl=h/n;
	else ansl=h/n+1;
	return ansl;
} 
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	I AK CSP
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int ming=1;
	for(int i=2;i<=n*m;i++)if(a[i]>a[1])ming++;
	int ansl=quzheng(ming);
	int ansh=ming%n;
	if(ansh==0)ansh=n;
	if(ansl%2==0)ansh=n+1-ansh;
	cout<<ansl<<" "<<ansh;
	return 0;
}