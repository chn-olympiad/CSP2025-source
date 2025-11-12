#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a[5*10000+3][5*10000+3];
	long long n,m;
	cin>>n>>m;
	long long b[5*10000+3];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	long long u=b[1];
	sort(b+1,b+n*m+1);
	int w;
	for(int i=1;i<=n*m;i++){
	
		if(b[i]==u){
			w=i;
			break;
		}
	}
	w=n*m+1-w;
	
	if(w%n==0){
		if(w/n%2==0){
			cout<<w/n<<" "<<1;
			
		}
		else{
			cout<<w/n<<" "<<m;
			
		}
	}
	else{
		int x,y;
		y=w/n+1;
		if(y%2==0){
			x=y*n-w+1;
			cout<<y<<" "<<x;
			
		}
		else{
			x=w-n*(y-1);
			cout<<y<<" "<<x;
		
		}
	}
	return 0;
}
