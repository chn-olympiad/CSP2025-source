#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int R;
	cin>>n>>m;
	cin>>R;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(R<a[i]) pm++; 
	}
	if(pm%n==0){
		if((pm/n)%2==0){
			cout<<pm/n<<" "<<1;
		}
		else{
			cout<<pm/n<<" "<<n;
		}
	}
	else{
		if((pm/n+1)%2==0){
			cout<<(pm/n)+1<<" "<<n-(pm%n)+1;
		}
		else{
			cout<<(pm/n)+1<<" "<<(pm%n);
		}
	}
	return 0;
}
