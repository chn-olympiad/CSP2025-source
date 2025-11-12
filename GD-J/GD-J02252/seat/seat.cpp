#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=66666;
stringstream ss;
string s;
int t,a[N],x,y,n,m;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==x){
			y=n*m-i+1;break;
		}
	}
	if(y%n==0)
	{
		if(y/n%2==1)cout<<y/n<<" "<<n;
		else cout<<y/n<<" "<<1;
	}
	else {
		if((y/n+1)%2==1)cout<<y/n+1<<" "<<y%n;
		else cout<<y/n+1<<" "<<n-y%n+1;
	}
	return 0;
}
