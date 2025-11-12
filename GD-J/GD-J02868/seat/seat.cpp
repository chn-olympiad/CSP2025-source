#include<iostream>
#include<algorithm>
using namespace std;

int a[100100];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,k,t,id;
	cin>>n>>m;
	for(int i = 1; i <= n*m; i++){
		cin>>a[i];
		if(i == 1){
			k = a[i];
		}
	}
	sort(a+1,a+n*m+1,greater<int>());
	t = 1;
	id = 0;
	for(int i = 1; i <= n; i++){
		if(t == 1){
			for(int j = 1; j <= m; j++){
				if(a[++id] == k){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j = m; j >= 1; j--){
				if(a[++id] == k){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		t = 1-t;
	}
	return 0;
} 
