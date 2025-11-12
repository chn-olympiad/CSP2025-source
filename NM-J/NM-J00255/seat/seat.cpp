#include<bits/stdc++.h>
using namespace std;
int b[12][12];//¾ØÕó 
void solve(){
	int n,m;
	cin >> n >> m;
	int y=0;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=n;j++){
			cin >> b[i][j];
		    y=b[1][1];
		} 
		
	}
	sort(b,b+1);
	for(int i=1;i<=n;i++){//ÐÐ 
		for(int j=1;j<=n;j++){//ÁÐ 
			if(b[i][j]==y){
				cout << b[i][j];
			}
		}
	}
}
int main(){
	found("seat.in","r","setin");
	found("seat.out","w","setout"); 
	solve();
	return 0;
}
