#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],x,y,b,c,d;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	y=a[1];
	sort(a+1,a+1+x,cmp);
	for(int i=1;i<=x;i++){
		if(i==n){
			c=1;
			d=i;
		}
		else if(a[i]==y){
			c=i/m+1;
			d=i%n;
		}
	}
	b=c%2;
	if(b==1){
		cout<<c<<" "<<d;
	}
	else{
		cout<<c<<" "<<m-d+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
