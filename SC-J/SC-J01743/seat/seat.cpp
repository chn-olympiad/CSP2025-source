#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],p,x,y,now=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	p=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==p){
			x=now/n;
			if(x%2==0){
				y=now%n;
			}
			if(x%2==1){
				y=(now+1)%n;
			}
			cout<<x+1<<" "<<y+1;
			return 0;
		}
		now++;
	}
	
}