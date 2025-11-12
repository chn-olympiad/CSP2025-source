#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],x,y=0,b=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]!=x){
			y+=1;
		}
		else if(a[i]==x)
		{
			break;
		}
	}
	y=n*m-y;
	for(int i=1;i<=m;i++){
		if(y>n)
		{
			y-=n;
			b+=1;
		}
		else if(y<=n)
		{
			if(b%2==1){
				cout<<b<<' '<<y;
			}
			else if(b%2==0){
				cout<<b<<' '<<n-y+1;
			}
			return 0;
		}
	}
}
