#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15],r;
int n,m;
int x,y;
int flag;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			flag=i;
		}
	}
	if(flag%n==0)x=flag/n;
	else x=flag/n+1; 
	if(x%2==1){
		y=flag%n;
		if(y==0)y=n;
	}
	else{if(flag%n==0){
			y=1;
		}
		else y=n-(flag%n)+1;
		
	}
	cout<<x<<" "<<y;
	return 0;
}
