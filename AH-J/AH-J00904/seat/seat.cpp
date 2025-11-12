#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[105];
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>b[0];
	int k = b[0];
	for(int i = 1;i<n*m;i++){
		cin>>b[i];
	}
	sort(b,b+105,px);
	int c = 0;
	for(int l = 1;l<=m;l++){
		if(l%2 == 1){
			for(int h = 1;h<=n;h++){
				if(b[c] == k){
					cout<<l<<" "<<h;
					return 0;
				}
				c++;
			}
		}
		else{
			for(int h = n;h>0;h--){
				if(b[c] == k){
					cout<<l<<" "<<h;
					return 0;
				}
				c++;
			}
		}
	}
	return 0;
}
