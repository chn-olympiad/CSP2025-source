#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100005];

bool cmp(int a,int b){
	return a>b;
}
int l,k,x,t,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			t=i;
			break;
		}
	}
	if(t%n==0){
		k=t/n;
	}else k=t/n+1;
	if(k%2!=0){
		if(t%n==0) l=n;
		else l=t%n;
	}else{
		if(t%n==0) l=n;
		else l=n-t%n+1; 
	}
	cout<<k<<" "<<l;  
	return 0;
}
 
