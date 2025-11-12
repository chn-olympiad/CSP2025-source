#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	int n,m,b,c,j,d=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			j=d;
			break;
		}
		d++;
	}
	b=j/n;
	c=j%n;
	if(b%2==0){
		if(c==0){
			c=1;
		}
		else{
			b++;
		}
	}
	else{
		if(c==0){
			c=n;
		}
		else{
			b++;
			c=n-c+1;
		}
	}
	cout<<b<<" "<<c;
	return 0;
}
