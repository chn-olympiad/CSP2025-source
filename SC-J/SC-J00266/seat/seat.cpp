#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for(int i=0;i<=n*m;i++){
		cin>>a[i];
		s=max(a[0],a[i]);
		
	}
	cout<< n<<' '<<m;
	
	return 0;
}