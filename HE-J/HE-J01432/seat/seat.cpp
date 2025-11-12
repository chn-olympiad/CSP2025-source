#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,h;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		int n=a[1];
	}
	for(int i=2;i<=n*m;i++){
		if(a[1]>a[i])
		h++;
	}
	int v=m/2;
	if(h==m*n){
		cout<<"1"<<" "<<1;
	}
	if(h==0){
		cout<<n<<" "<<v;
	}
	
	
	return 0;
} 
