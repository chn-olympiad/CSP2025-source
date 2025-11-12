#include<bits/stdc++.h>
using namespace std;
int x,y,a[10005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			r=i;
			break;
		}
	}
	x=r/n;
	if(r%n!=0){
		x++;
	}
	if(x%2==0){
		y=m-r%n;
	}else{
		y=r%n;
	}
	if(r%n==0){
		y=m;
	}
	cout<<x<<" "<<y;
	return 0;
}
