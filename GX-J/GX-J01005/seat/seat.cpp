#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,x,y;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(c==a[i])c=i;
	}
	
	
	
	
	
	
	
	if(c%n==0)y=c/n;
	else y=c/n+1;
	if(y%2==0)x=abs(c%n-n)+1;
	else if(c%n==0)x=n;
	else x=c%n;
	
	cout<<y<<' '<<x;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
