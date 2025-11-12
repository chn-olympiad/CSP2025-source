#include<bits/stdc++.h>
using namespace std;
int a[1100],n,m,c,b,e,d;
bool cmp(int x,int y){
	if(x>y) return true;
	else return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
		}
		}
	d=(c-1)/n+1;
	if(d%2==1){
		if(c%n==0){
			e=n;
		}
		else{
			e=c%n;
		}
	}
	else{
		if(c%n==0){
			e=1;
		}
		else{
			e=n-c%n+1;
		}
	}
	cout<<d<<" "<<e;
	return 0;
} 
