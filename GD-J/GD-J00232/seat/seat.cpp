#include<iostream>
using namespace std;
int n,m,x,y,b=1,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>y;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>y) b++;
	}
	ans=b/n;
	if(b%n) ans++;
	cout<<ans<<" ";
	b%=m;
	if(!b) b=m;
	if(ans%2==1) cout<<b;
	else cout<<m-b+1;
}
