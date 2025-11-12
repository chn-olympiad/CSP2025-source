#include<bits/stdc++.h>
#define For(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
int x[300];
bool cmpp(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	For(i,1,n*m){
		cin>>x[i];
	}
	int w=x[1];
	int f=0;
	sort(x+1,x+1+n*m,cmpp);
	For(i,1,n*m){
		if(x[i]==w){
			f=i;
		}
	}
	int a;
	a=f/n;
	if(f%n==0){
		if(a%2==0){
			cout<<a<<' '<<1;
		}else{
			cout<<a<<' '<<n;
		}
		return 0;
	}
	cout<<a+1<<' ';
	if(a%2==0){
		cout<<f-a*n;
	}else{
		cout<<(n+1)-(f-a*n);
	}	
	return 0;
}
