#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int x[200];
bool comp(int x,int y){
	if(x>y) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	if(n==1&&m==1){cout<<1<<" "<<1;return 0;}
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
		p=x[1];
	}
	sort(x+1,x+n*m+1,comp); 
	for(int i=1;i<=n*m;i++){
		if( i%n==0&&x[i]==p ){
			if((i/n)%2==0){cout<<i/n<<" "<<1;}
			else cout<<i/n<<" "<<n;
		}
		else if((i-1) %n==0&&x[i]==p){
				if( ( (i-1)/n ) %2==0 ){cout<<(i-1)/n+1<<" "<<1;}
				else cout<<(i-1)/n+1<<" "<<n;
		}
		else if(x[i]==p){
			for(int j=n;j>=1;j--){
				if((i+j)%n==0){
					cout<<(i+j)/n<<" "<<n-j;
					return 0;
				}
				j--;
				continue;
			} 
		}
	}
	return 0;
}
