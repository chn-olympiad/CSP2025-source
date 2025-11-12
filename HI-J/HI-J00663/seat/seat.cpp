#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=0;i<=n*m-1;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	if(a[0]==x){
			cout<<1<<" "<<1;
		}
		else{
			cout<<n<<" "<<m;
		}
return 0;
} 
