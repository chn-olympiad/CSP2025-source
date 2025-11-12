#include<bits/stdc++.h>
using namespace std;
int main(){
		freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(a[1]==1){
		if(m%2==1){
			cout<<m<<" "<<n;
			return 0;
		}
		if(m%2==1){
			cout<<m<<" 1";
			return 0;
		}
	}
	cout<<n<<" 1";
		return 0;
}
