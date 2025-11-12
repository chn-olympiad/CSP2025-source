#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[100001],p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    cin>>a[(i-1)*n+j];
    p=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==p){
			cout<<y<<" "<<x<<"\n";
			return 0;
		}
		if(y&1){
			x++;
			if(x==n+1) y++,x=n;
		}
		else{
			x--;
			if(x==0) y++,x=1;
		}
	}   
	return 0;
}
