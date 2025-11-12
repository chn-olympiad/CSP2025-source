#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[0],a[1]=a[0];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) if(a[0]==a[i]){x=n*m-i+1;break;}
	cout<<(x+n-1)/n<<" ";
	if((x+n-1)/n%2==1) cout<<(x-1)%n+1;
	else cout<<n+1-x%n;
	return 0;
}//AKIOI!!!
