#include<bits/stdc++.h>
using namespace std;
int  n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	} 
	int r=a[1],l;
	//cout <<r<<endl;
	sort(a+1,a+1+n*m);
	/*
	for(int i=1;i<=n*m;i++){
		cout <<a[i]<<endl;
	}
	*/
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			l=n*m-i+1;
			break;
		}
	}
	//cout <<3/2<<" "<<1/2<<endl;
	//cout <<l<<" "<<l/n<<endl;
	int x,y;
	if((l/n+(l%n!=0))%2==0){
		y=l/n+(l%n!=0);
		if(l%n==0)x=1;
		else x=n-(l%n-1);
	}else{
		y=l/n+(l%n!=0);
		//cout <<l/n<<endl;
		if(l%n==0)x=n;
		else x=l%n;
	}
	cout <<y<<" "<<x;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
