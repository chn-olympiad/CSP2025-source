#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],c,r;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int t=a[1],p=0;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t) p=i;
	}
	
	if(p<=n) c=1,t=p;
	if(p>n){
		c=p/n+1;
		if(c%2==1){
			if(p%n==0) t=n;
			else t=p%n;
		}
		else{
			if(p%n==0) t=1;
			else t=n-p%n+1;
		}
    }
	cout<<c<<" "<<t;
	
	return 0;
}
