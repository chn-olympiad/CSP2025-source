#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,x,y,a[105],c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin >> n>>m;
	c=n*m;
	for(int i=0;i<c;i++){
		cin >>a[i];
	}
	int b=a[0];
	sort(a,a+c,cmp);
	for(int i=0;i<c;i++){
		if(a[i]==b){
			b=i+1;
			break;
		}
	}
	x=b/n;
	if(x*n<b){
		x++;
	}
	if(x%2==0){
		y=n-(b%n-1);
	}else{
		y=b%n;
	}
	if(y==0){
		y=n;
	}
	cout<<b<<' '<<x<<' '<<y;
	return 0;
}
