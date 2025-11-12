#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int t=a[0];
	sort(a,a+n*m,cmp);
	int x;
	for(int i=0;i<n*m;i++){
		if(a[i]==t){
			x=i+1;
		}
	}
	int c,r;
	c=x/n;
	if(x%n)c++;
	if(c%2==1){
		r=x%n;
		if(r==0)r=n;
	}else{
		int t=x%n;
		if(t==0)t=n;
		r=n-t+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

