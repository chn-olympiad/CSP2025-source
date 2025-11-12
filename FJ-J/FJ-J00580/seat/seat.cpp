#include <bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int sb,int sr){
	return sb>sr;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=0,y=0,z=0;
	cin >> n >> m;
	for (int i=0;i<n*m;i++){
		cin >> a[i];
	}
	x=a[0];
	sort(a,a+(n*m),cmp);
	for (int i=0;i<n*m;i++){
		if(a[i]==x){
			y=i+1;
			break;
		} 
	}
	if(y%n!=0){
		z=y/n+1; 
	}
	else{
		z=y/n-1;
	}
	cout << z <<" ";
	if(z%2==1){
		if(y%n==0){
			cout << n;
		}
		else{
			cout << y%n;
		}
	}
	else{
		if(y%n==0){
			cout << 1;
		}
		else{
			cout << n-y%n+1;
		}
	} 
	return 0;
}
