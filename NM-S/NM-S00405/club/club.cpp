#include<bits/stdc++.h>
using namespace std;
int n,t,sum = 0, s = 3;
int a[100010][3];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		int max = -1;
		for(int x = 1; x <= n; x++){
			for(int y = 1; y <= 3; y++){
				int inp = 0;
				cin >> inp;
				a[x][y] = inp;
			}
		}
		for(int x = 1; x <= n; x++){
			max = -1;
			for(int y = 1; y <= 3; y++){
				if(max < a[x][y]){
					max = a[x][y];			
				}
			}
			sum += max;
		}
		cout << sum << endl;
	}
	return 0;
}
