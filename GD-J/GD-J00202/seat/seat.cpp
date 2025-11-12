#include<bits/stdc++.h>
using namespace std;

int a[200];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n*m; i++){
		cin>>a[i];
	}
	int p = a[1],id;
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++){
		if(a[i] == p){
			id = i;
			break;
		}
	}
	int c = 1,r;
	while(1){
		if(id > n){
			id -= n;
			c++;
		}
		else{
			if(c%2 == 1){
				r = id;
			}
			else{
				r = n-id+1;
			}
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
