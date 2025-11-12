#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n*m-1];
    for(int y = 0;y<n*m;y++){
    	cin>>a[y];
	}int R = a[0];
	int k = 0;
	for(int y = 1;y<n*m;y++){
		if(a[y] > R){
			k++;
		}
	}
	int c = k / n + 1;
	int r = k % n + 1;
	if(c % 2 == 0){
		r = m - r + 1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
