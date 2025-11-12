#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,inall,r,x = 1,y = 1,a[105];
	cin>>n>>m;
	inall=n*m;
	for(int i = 0;i<inall;i++)cin>>a[i];
	r = a[0];
	sort(a,a+inall);
	for(int i = inall-1;i>=0;i--){
		if(a[i] == r){
			cout<<x<<' '<<y;
			break;
		}
		if(x%2 == 1 && y == n) x++;
		else if(x%2 == 1 && y < n) y++;
		else if(x%2 == 0 && y == 1) x++;
		else if(x%2 == 0 && y > 1) y--;
	} 
	return 0;
}
