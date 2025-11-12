#include<bits/stdc++.h>
using namespace std;
int n,m;//n hang,m lie
int a[105];
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
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	
	
	int flag;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) flag=i; 
	}
	
	
	
	int c,r;//c lie, r hang
	if(flag%n==0){
		c=flag/n;
		if(c%2==1) r=n;
		else r=1;
	}else{
		c=1+flag/n;
		if(c%2==1){
			r=flag%n;
		}else{
			if(flag%n==1) r=n;
			else r=n-flag%n+1;
		}
	}
	
	
	
	
	cout<<c<<" "<<r;
	return 0;
}
