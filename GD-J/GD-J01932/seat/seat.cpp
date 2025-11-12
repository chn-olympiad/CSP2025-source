#include<bits/stdc++.h>
using namespace std;
int poi=1,n,m,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1];
	a[0]=0;
	cin>>k;
	a[1]=k;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			poi=n*m-i+1;
			break;
		}
	}
	if(poi*1.0/n==poi/n){
		cout<<poi/n<<" ";
		if((poi/n)%2==0) cout<<1;
		else cout<<n;
	}else{
		cout<<poi/n+1<<" ";
		int x=poi/n+1;
		if(x%2!=0) cout<<poi%n;
		else cout<<n-poi%n+1;
	}
	return 0;
}

