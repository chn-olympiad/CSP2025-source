#include <bits/stdc++.h>
using namespace std;
int n,m;
int x,y;
int a[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out"."w",stdout);
	
	cin>>n>>m;
	int k = n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	int b = a[1];
	sort(a+1,a+k+1,cmp);
	
	int v=0;
	for(int i=1;i<=k;i++){
		if(a[i]==b)v=i;
	}
	y = v/n+(v%n!=0?1:0);
	
	if(y%2==0&&v%n!=0)x=n+1-v%n;
	else if(y%2==0&&v%n==0)x=1;
	else if(y%2==1&&v%n!=0)x=v%n;
	else if(y%2==1&&v%n==0)x=n;
	
	cout<<y<<" "<<x;
	return 0;
}