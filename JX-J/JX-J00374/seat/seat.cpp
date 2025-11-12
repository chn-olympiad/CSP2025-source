#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m;
int a[110];
int x,y;
int p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			p=i;
		}
	}
	if(p%n==0){
		y=p/n;
	}
	else{
		y=p/n+1;
	}
	if(y%2==0){
		for(int i=n*(y-1)+1,h=n;i<=n*y;i++,h--){
			if(p==i){
				x=h;
			}
		}
	}
	if(y%2==1){
		if(p%n==0){
			x=n;
		}
		else{
			x=p%n;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
