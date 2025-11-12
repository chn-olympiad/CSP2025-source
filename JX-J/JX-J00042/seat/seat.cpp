#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=(n*m)-i+1;
			break;
		}
	}
	cout<<(k+n-1)/n<<' ';
	k=k%(2*n);
	if(k==0)cout<<n<<endl;
	else if(k<=n)cout<<k<<endl;
	else cout<<(2*n-k+1)<<endl;
	return 0;
}
