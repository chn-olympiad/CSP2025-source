#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,i,m,k,l=1,p=1;
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int r=1,c=1;
	while(a[l]!=k){
		c+=p;
		if(c>n){
			c=n;
			r++;
			p=-p;
		}
		if(c<=0){
			c=1;
			r++;
			p=-p;
		}
		l++;
	}
	cout<<r<<' '<<c; 
	return 0;
} 
