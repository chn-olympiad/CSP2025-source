#include<bits/stdc++.h>
using namespace std;
string s;
int a[111],n,m;
char c;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int S=n*m,r,x,y,z;
	for(int i=1;i<=S;i++){
		scanf("%d",&a[i]);
		if(i==1){
			r=a[i];
		}
	}
	sort(a+1,a+1+S,cmp);
	for(int i=1;i<=S;i++){
		if(a[i]==r){
			z=i;
			break;
		}
	}
	x=z/n;
	if(z%n!=0){
		x++;
	}
	if(x%2==1){
		y=z-n*(x-1);
		cout << x <<" " << y ;
	}else{
		y=n-z%n+1;	
		cout << x<<" "<<y;
	}
	
	
	return 0;
}
