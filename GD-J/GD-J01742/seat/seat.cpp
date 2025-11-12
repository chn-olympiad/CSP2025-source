#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m, x;
    int a[1005]; 
    cin >> n >> m;
    int cnt = n*m+1;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	x = a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2 != 0){
			for(int j=1;j<=n;j++){
				cnt--;
				if(a[cnt] == x){
					cout << i << " " << j; 
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt--;
				if(a[cnt] == x){
					cout << i << " " << j;
				}
			}
		}
	}
    return 0;
}

