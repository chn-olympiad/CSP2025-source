#include <bits/stdc++.h>
using namespace std;

int a[105];
int n,m;
bool o(int x, int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+(n*m),o);
	int s=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			 s=i;
			break;
		}
	}
	int c=s/n;
	if(s%n!=0){
		c++;
		s-=(c-1)*n;
		cout<<c<<" ";
	}
	else{
		cout<<c<<" ";
		s-=c*n;
	}
	
	
	if(s%2==1){
		cout<<s;
	}
	else{
		cout<<n-s;
	}
}