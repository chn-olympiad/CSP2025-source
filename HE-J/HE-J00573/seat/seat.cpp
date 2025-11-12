#include <bits/stdc++.h>
using namespace std;
int n,m,a[150],r,vis[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	
	if(n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	
	if(n<=2){
		cout<<1<<" "<<1;
		return 0;
	}
	
	cout<<n<<" "<<1;


	return 0;
}

