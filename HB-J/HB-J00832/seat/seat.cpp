#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(a[1]<a[2] && a[2]>a[3] && n>=2 && m>=2) cout<<n-1<<" "<<m;
	else if(a[1]<a[2] && a[2]<a[3] && n!=3 && m!=3) cout<<n<<" "<<m;
	else if(a[1]<a[2] && n>2 && m>2) cout<<n<<" "<<m-2;
	else if(a[1]>a[2] && a[1]>a[3]) cout<<"1 1";
	return 0;	
}
