#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int n,m,p,a[105],l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>p;
	a[1]=p;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=m*n;i>=1;i--){
		if(a[i]==p){
			l=m*n-i+1;
		}
	}
	int x=l/m+1,y=l%m;
	if(y==0){
		x--;
		y=m;
	}
	cout<<x<<" ";
	if(x%2){
		cout<<y;
	}else{
		cout<<m-y+1;
	}
	return 0;
}