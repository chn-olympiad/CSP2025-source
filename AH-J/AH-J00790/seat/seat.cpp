#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=1,y=1,k,turn=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
		cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==k){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		x+=turn;
		if(x>n){
			x--;
			y++;
			turn=-1;
		}
		if(x<1){
			x++;
			y++;
			turn=1;
		}
	}
    return 0;
}
