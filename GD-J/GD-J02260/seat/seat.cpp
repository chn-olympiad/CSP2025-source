#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1000005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)cin >> a[i];
	int t=a[1];
	sort(a+1,a+n*m+1);
	int r=m*n-(lower_bound(a+1,a+n*m+1,t)-a)+1;
	if(r==1){
		cout << 1 << " " << 1;
		return 0;
	}
	if(r%m==0){
		if((r/m)%2==0){
			cout << r/m << " " << 1;
			return 0;
		}else{
			cout << r/m << " " << m;
			return 0;
		}
	}
	if((r/m+1)%2==0){
		cout << r/m+1 << " " << r%n+1;
		return 0;
	}else{
		cout << r/m+1 << " " << m-r%(m+1)+1;
		return 0;
	}
	return 0;
} 

