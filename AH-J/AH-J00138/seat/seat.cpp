#include <bits/stdc++.h>
using namespace std;
int x[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>x[i];
	}
	int a=x[0],b=0;
	sort(x,x+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a==x[i]){
			b=i+1;
		}
	}
	int c=b/n+1,r=b%n;
	if(r==0){
		c--;
		r=n;
	}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

