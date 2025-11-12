#include<bits/stdc++.h>
using namespace std;
int n,m,p,q,r,a[1010];
bool l(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	r=n*m;
	for(int i=1;i<=r;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+r+1,l);
	for(int i=1;i<=r;i++){
		if(a[i]==p){
			q=i;
			break;
		}
	}
	if(q%n==0){
		if((q/n)%2!=0){
			cout<<q/n<<" "<<n;
		}
		else{
			cout<<q/n<<" "<<1;
		}
	}
	else{
		if((q/n+1)%2!=0){
			cout<<q/n+1<<" "<<q%n;
		}
		else{
			cout<<q/n+1<<" "<<n-q%n+1;
		}
	}
	return 0;
}
