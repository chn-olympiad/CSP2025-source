#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],x,y,r=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i>=2){
			if(a[i]>a[1]) r++;
		}		
	}
	if(r%n==0) x=r/n;
	else x=r/n+1;
	int z=2*n;
	if(x%2==1) y=r%z;
	else y=n-r%n+1;
	cout<<x<<" "<<y;
	return 0; 
}
