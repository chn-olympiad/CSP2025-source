#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],f; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if (m%2==1){
		cout<<m<<" "<<n;
	}else {
        cout<<m<<" "<<1;
	return 0;
    } 
}
