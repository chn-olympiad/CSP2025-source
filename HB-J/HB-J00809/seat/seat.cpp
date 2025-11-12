#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[111];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int xiao=a[1];
	sort(a+1,a+n*m+1);
	int x=1,y=1,t=n*m,f=1;
	for(int i=1;i<=n*m;i++){
		if(a[t]==xiao){
			cout<<y<<" "<<x;
			return 0;
		}
		if(f==1){
			if(x+1<=n) x++;
			else if(x+1>n){
				y++;
				f=0;
			}
		}
		else if(f==0){
			if(x-1>=1) x--;
			else if(x-1<1){
				y++;
				f=1;
			}
		}
		t--;
	}
	return 0;
}
