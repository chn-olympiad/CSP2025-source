#include <bits/stdc++.h>
using namespace std;
int n,m,b;
int a[105];
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n*m ; i++){
		cin >> a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1 ; i <= n*m ; i++){
		if(a[i]==b){
			if(i%n==0){
				if((i/n)%2==1){
					cout << i/n << " " << n;
					break;
				}else{
					cout << i/n << " " << 1;
					break;
				}
			}
			if((i/n)%2==1){
				cout << i/n+1 << " " << n-i%n+1;
				break;
			}else{
				cout << i/n+1 << " " << i%n;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
