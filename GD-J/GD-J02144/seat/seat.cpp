#include<bits/stdc++.h>
using namespace std;
int n,m;
struct nd{
	int x;
	bool y;
};
bool pai(nd num,nd sum){
	if(num.x>sum.x){
		return true;
	}
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nd a[1000];
	nd b[100][100];
	for(int i = 1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y = 0;
	}
	a[1].y = 1;
	sort(a+1,a+n*m+1,pai);
	long long w;
	for(int i = 1;i<=n*m;i++){
		if(a[i].y){
			w = i;
		}
	}
	int t = w/n;
	if(t*n<w){
		t+=1;
	}
	int u = t%2;
	int g = 0;
	if(u){
		if(w%n==0){
			g = n;
		}
		else{
			g = w%n;
		}
		
	}
	else{
		if(w%n==0){
			g = 1;
		}
		g = (n+1)-w%n;
	}
	
	cout<<t<<' '<<g;
	
	
	return 0;
} 
