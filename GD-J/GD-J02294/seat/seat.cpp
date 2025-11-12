#include<iostream>
#include<vector>
using namespace std;

int m,n,tag,x = 1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	vector<int>a(100,0);
	for(int i = 1;i<=m*n;i++){
		cin>>a[i];
	}
	tag = a[1];
	for(int i = 1;i<=m*n;i++){
		if(a[i]>tag){
			x++;
		}
	}
	cout<<(x-1)/n+1<<' ';
	int y = x%(2*n);
	if(y<=n){
		cout<<y;
	}else{
		cout<<2*n-y+1;
	}
}
