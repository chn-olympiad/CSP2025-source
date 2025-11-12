#include<bits/stdc++.h>

using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m,l;
	for(int i = 1;i<=t;i++){
		cin>>a[i];
	}
	l=a[1];int k=0;
	sort(a+1,a+t+1,cmp);
	for(int i = 1;i<=t;i++){
		if(a[i]==l){
			k=i;
			break;
		}
	}int c,r;
	if(k<n){
		c=1;
	}else if(k%n==0){
		c=k/n;
	}else{
		c=k/n+1;
	}
	if(c%2==0){
		if(k%n==0){
			r=n;
		}
		else r=n-((k%n)-1);
	}else{
		if(k%n==0)
		r=k;
		else r=k%n; 
	}
	cout<<c<<' '<<r;
	return 0;
}
