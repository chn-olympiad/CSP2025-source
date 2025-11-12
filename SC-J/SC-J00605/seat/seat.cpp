#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],f,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	f=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)if(a[i]==f){ans=i;break;}
	cout<<(ans+n-1)/n<<" "<<((((ans+n-1)/n)%2==1)?(ans-1)%n+1:n-ans%n+1);
	return 0;
}