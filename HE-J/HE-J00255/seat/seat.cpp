#include<bits/stdc++.h>
using namespace std;
int m,n,a[520][520],t[521]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int x = n*m;
	for(int i=1;i<=x;i++){
			cin >> a[i][i];
			t[i] = a[i][i];
	}
	sort(t+1,t+1+x,cmp);
	for(int i=1;i<=x;i++){
		if(t[i] == a[1][1]){
			if(i%n==0) {
				cout << i/n <<' '<< n;
				return 0;
			}
			if(i%n==1){
				cout << i/n+1 <<' ' << n;
				return 0;
			}
			else {
				cout <<i/n<<' '<< i%n;
				return 0;
			}
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
