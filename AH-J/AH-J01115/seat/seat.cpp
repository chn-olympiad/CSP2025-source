#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int m,n,s;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			if(i%n==0){
				cout<<i/n<<" ";
				if((i/n)%2==0){
					cout<<1;
				}
				else{
					cout<<n;
				}
			} 
			else{
				cout<<i/n+1<<" ";
				if((i/n+1)%2==0){
					cout<<n+1-i%n;
				}
				else{
					cout<<i%n;
				}
			}
		}
	}
	return 0;
}
