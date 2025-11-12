#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],b,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]>b){
			q++;
		}
	}
	q++;
	if(q/n%2==0 && q%n!=0){
		if(q%n!=0){
			cout<<q%n<<" "<<q/n+1;
			return 0;
		}
		else{
			cout<<n<<" "q/n;
			return 0;
		}
	}
	else{
		if(q%4==0){
			cout<<1<<" "<<q/4;
			return 0;
		}
		else{
			cout<<4-q%4+1<<" "<<q/n+1;
			return 0;
		}
	}
	return 0;
}
