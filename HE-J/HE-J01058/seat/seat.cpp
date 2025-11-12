#include<bits/stdc++.h>

using namespace std;
int b[10030];
int n,m;
int x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> b[i];
		if(i==1){
			x=b[i];
		}
	}

	return 0;
} 
