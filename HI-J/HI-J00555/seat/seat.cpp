#include<bits/stdc++.h>
using namespace std;
int x ;
int n,m;
int a[10000100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int w = n*m;
	for(int i = 1;i<=w;i++){
		cin >> a[i];
		if(a[i]>a[1]){
			x++;
		}
	}
	int s=x%n;
	int r =x-x%n;
	int f = r/n+1;
	if(f%2!=0){
			cout << f << ' ' << s+1;	
	}	
	else if(f%2==0){
		cout << f << " "<< m-s;
	}
	return 0;
}
