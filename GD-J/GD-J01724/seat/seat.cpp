#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],r,x,y,z;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>r){
			z++;
		}
	}
	z++;
	x=z/n;
	if(z%n){
		x++;
	}
	y=z%n;
	if(z%n==0){
		y=n;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
} 
//#Shang4Shan3Ruo6Shui4
