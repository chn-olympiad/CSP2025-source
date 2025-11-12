#include <bits/stdc++.h>
using namespace std;
int n,m,a[100],c,t,f,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	c=a[0];
	sort(a,a+n*m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			d=-i+1;
			if(i%2==0){
				t=1;
				f=n-d%n;		
			}
			else{
				t=n;
				f=d%n;
			}
			if(a[(i-1)*n+j-1]==c){
				if(d%n==0){
					cout<<d/n<<' '<<t;
				}
				else{
					cout<<d/n+1<<' '<<f;
				}
				break;
			}
		}	
	}
	return 0;
}
