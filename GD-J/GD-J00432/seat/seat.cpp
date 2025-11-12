#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
int a[105]; 
string b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cs=0,js=0;
	int l=0,r=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cs=a[1];
	sort(a+1,a+n*m+1);
	for(int j=n*m;j>=1;j--){
		if(a[j]==cs){
			js=n*m-j+1;
		}
	}
	if(js%n){
		if((js/n+1)%2==0){
			cout<<js/n+1<<' '<<n-js%n+1;
		}
		else{
			cout<<js/n+1<<' '<<js%n;
		}
	}
	else{
		if((js/n)%2==0){
			cout<<js/n<<' '<<1;
		}
		else{
			cout<<js/n<<' '<<n;
		}
	}
	return 0;
} 
