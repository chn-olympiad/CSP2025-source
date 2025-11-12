#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			int j=n*m-i+1;
			int y=(j-1)/n+1,x=(j-1)%n+1;
			cout<<y<<" "<<((y%2==1)?x:(n-x+1));
			return 0;
		}
	}
	return 0;
}
