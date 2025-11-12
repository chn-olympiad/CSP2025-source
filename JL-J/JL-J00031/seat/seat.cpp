#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,a[100];
void cmp(){
	for(int i=0;i<n*m;i++){
		int mx=0,mxx;
		for(int j=i;j<n*m;j++){
			if(a[j]>mx)mx=a[j],mxx=j;
		}
		swap(a[i],a[mxx]);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	z=a[0];
	cmp();
	for(int i=0;i<n*m;i++)if(a[i]==z){z=i+1;break;}
	x=(z+n-1)/n;
	if(x%2==1){
		if(z<=n)y=z;
		else y=z%n;
	}
	else y=n-(z%n)+1;
	cout<<x<<" "<<y;
}
//JL-J00031
