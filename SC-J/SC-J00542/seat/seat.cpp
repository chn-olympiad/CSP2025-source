#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10001];
int b;
int c;
int x,y;
int h,l;
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]>=b){
			c++;
		}
	}
	if(c==n*m){
		cout<<n<<' '<<m;
		return 0;
	}
	x=c/n;
	y=c%n;
	if(y==0){
		l=x;
	}else l=x+1;
	if(l%2!=0){
		if(n!=c) h=y;
		else h=n;
	}else{
		if(n!=c) h=n;
		else h=n-y;
	}
	cout<<l<<' '<<h;
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/