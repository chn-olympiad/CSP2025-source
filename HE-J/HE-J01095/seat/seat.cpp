#include <bits/stdc++.h>
using namespace std;
bool k(int x,int y){
	return (x > y);
}
int n,m,q,a[105],p,t,u;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	q = n*m;
	for(int i = 1;i <= q;i++) cin >>a[i];
	p = a[1];
	sort(a+1,a+q+1,k);
	for(int i = 1;i <= q;i++){
		if(a[i] == p){
			t = i;
			break;
		}	
	}
	for(int i = 1;i <= m;i++){
		if(i % 2){
			for(int j = 1;j <= n;j++){
				if(++u == t) cout <<i<<" "<<j;
			}
		}
		else{
			for(int j = n;j >= 1;j--){
				if(++u == t) cout <<i<<" "<<j;
			}
		}
	} 
}
