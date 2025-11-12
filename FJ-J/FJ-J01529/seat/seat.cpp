#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[105];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l = n*m;
	for(int i=1; i <= l; i++) cin>>a[i];
	k = a[1];
	sort(a+1,a+l+1,cmp);
	int x=1, y=1;
	bool f=0;
	for(int i=1; i <= l; i++){
		if(a[i] == k){
			cout<<y<<" "<<x;
			break;
		}
		if(!f){
			if(x < n) x++;
			else if(x == n){
				y++;
				f ^= 1;
			}
		}
		else if(f){
			if(x > 1) x--;
			else if(x == 1){
				y++;
				f ^= 1;
			}
		}
	}
	return 0;
}
