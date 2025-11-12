#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 105;
int Q = 0;
int n,m;
int a[N];
int me;
int r(int a,int b){
	return a>b;
}
void o(int num){
	int x,y;
	//cout<<num<<endl;
	y=num/n;
	if(num%n!=0)y++;
	if(y%2==1){
		if(num%n==0)x=num;
		else x=num%n;
	}
	else x=n-num%n+1;
	cout<<y<<" "<<x;
	return ;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)me=a[i];
	}
	sort(a+1,a+1+n*m,r);
	for(int i=1;i<=n*m;i++){
		if(a[i]==me){
			o(i);
			return ( Q ^ Q );
		}
	}
}
