#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[150],r;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	bool op=false;
	for(int i = 1;i <= n*m;i++){
		if(r == a[i]){
			cout<<y<<" "<<x;
			return 0;
		}
		if(!op){
			x++;
			if(x > n){
				x--;
				y++;
				op = true;
			}
			
		}
		else if(op){
			x--;
			if(x < 1){
				x++;
				y++;
				op = false;
			}
			
		}
		
	}
	return 0;
}
