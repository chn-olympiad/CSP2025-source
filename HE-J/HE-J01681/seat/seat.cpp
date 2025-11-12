#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int t=0,c=0,r=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			c=(i%n==0)?i/n:i/n+1;
			if(c%2==0)
				t=i/n+(n-(i/n+1)*n-i);
			else t=i;
			break;
		}
	}
 	r=(t%n==0)?n:t%n;
	cout<<c<<" "<<r;
	return 0;
}
