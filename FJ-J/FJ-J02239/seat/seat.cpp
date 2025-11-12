#include<bits/stdc++.h>
using namespace std;
int b[10005];
int n,m,x,c,r;
bool cmp(int a,int b){
	return  a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	x=b[1];
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i]==x){
			x=i;
			break;
		}
	}
	r=x/n+1;
	if(x%n==0)r--;
	if(r%2==0){
		c=n-x%n;
	}
	else c=x%n;
	if(c==0)c=n;
	cout<<r<<' '<<c;
	return 0;
}
