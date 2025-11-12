#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,as;
	int a[105];
	cin>>n>>m;           
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	if(a[1]<a[n*m]){
		cout<<n<<","<<m;
	}
	return 0;
} 
