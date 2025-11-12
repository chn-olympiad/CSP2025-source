#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NN=110;
int a[NN];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int l=a[1];
	sort(a+1,a+1+m*n);
	int hang,lie;
	for(int i=n*m;i>=1;i--){
		
		if(a[i]==l) {
			l=n*m-i+1;
			break;
		}
	}
	lie=(l-1)/m+1;
	
	if(lie%2==1) hang=(l-1)%n+1;
	else hang=m-(l-1)%m;
	cout<<lie<<' '<<hang;
	return 0;
} 
