#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],i1,x,y,p;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];	
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			i1=i;
			break;	
		}
	}
	if(i1%n==0){
		y=i1/n;
		if(y%2==1)x=n;			
		else x=1;			
	}
	else if(i1%n!=0){
		y=i1/n+1;
		if(y%2==1)x=i1%n;
		else x=n-i1%n+1;
	}
	cout<<y<<" "<<x;
} 