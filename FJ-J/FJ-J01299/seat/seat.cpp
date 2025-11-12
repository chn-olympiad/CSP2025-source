#include<bits/stdc++.h>
#define ct continue
using namespace std;
int n,m,x=1,y=1;
int a[105],pts;
int b[11][11]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}pts=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==pts){
			cout<<x<<" "<<y;
			return 0;
		}
		if((x%2==0)&&y>1){
			y--;ct;
		}if((x%2==0)&&y==1){
			x++;ct;
		}if((x%2==1)&&y<n){
			y++;ct;
		}if((x%2==1)&&y==n){
			x++;ct;
		}
	}
	return 0;
	//don't forget to delete the // before freopen!!! 
} 
