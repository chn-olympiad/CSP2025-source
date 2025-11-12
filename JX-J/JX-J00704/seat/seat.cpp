#include <bits/stdc++.h>
using namespace std;
int n,m,x,ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum;
	for(int i=1;i<=n*m;i++){
        cin>>x;
        if(i==1) sum=x;
        if(x>sum) ans++;
	}
	if(ans<n) cout<<1<<" "<<ans+1;
	else if((ans/n)%2==0) cout<<ans/n+1<<" "<<ans%n+1;
	else{
        cout<<ans/n+1<<" ";
        if(ans%n==0) cout<<n;
        else cout<<n-ans%n;
	}

	return 0;
}
