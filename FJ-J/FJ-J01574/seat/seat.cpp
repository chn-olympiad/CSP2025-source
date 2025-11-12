#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],k,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=m*n;i>=1;i--){
		if(a[i]==k){
			q=m*n-i;
			q++;
			break;
		}
	}
	int x,y;
	if(q<=n){
		cout<<1<<" "<<q<<endl;
		return 0;
	}else{
		if(q%n==0){
			x=q/n;
		}else{
			x=floor(q/n)+1;
		}
	}cout<<x<<" ";
	if(x%2==0){
		y=q%n;
		y=n-y;
		y++;
	}else{
		y=q%n;
		if(y==0){
			y+=n;
		}
	}
	cout<<y<<endl;
	
	return 0;
}
