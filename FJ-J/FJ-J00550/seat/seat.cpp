#include <bits/stdc++.h>
using namespace std;
int a[206];
int f(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int fen=a[1];
	int ge=0; 
	sort(a+1,a+1+n*m,f);
	for(int i=1;i<=n*m;i++){
		if(a[i]==fen){
			ge=i;
			break;
		} 
	}
	if(ge%n!=0){
		if((ge/n)%2==0){
			cout<<ge/n+1<<" "<<ge%n;
		}
		else{
			cout<<ge/n+1<<" "<<n-ge%n+1;
		}
	}
	else{
		if((ge/n)%2==0){
			cout<<ge/n<<" "<<1;
		}
		else{
			cout<<ge/n<<" "<<n;
		}
	}
	return 0;
}
	
