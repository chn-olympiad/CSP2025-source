#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a,cj[1005];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	cj[1]=a;
	for(int i=2;i<=n*m;i++){
		cin>>cj[i];
	}sort(cj+1,cj+n*m+1,cmp);
	
	ll ii=0;
	for(int i=2;i<=n*m;i++){
		if(cj[i]==a) {
			ii=i;
			break;
		}
	}
	
	if(ii%n==0) {
		if(ii/n%2==0){
			cout<<ii/n<<' '<<1;
		}else{
			cout<<ii/n<<' '<<n;
		}
	}else{
		if((ii/n+1)%2==0){
			cout<<ii/n+1<<' '<<n-ii%n+1;
		}else{
			cout<<ii/n+1<<' '<<ii%n;
		}
	}
	return 0;
} 
