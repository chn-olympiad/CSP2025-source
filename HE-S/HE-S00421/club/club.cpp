#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
int a[N][5];
int b[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	short f;
	cin>>f;
	for(int g = 1;g <= f;g++){
		int q;
		cin>>q;
		for(int i = 1;i <= q;i++){
			for(int j = 1;j <= 3;j++){
				cin>>a[i][j];
				b[i][j] = a[i][j];
			}
		}
		for(int i = 1;i <= 3;i++){
			if(a[1][i] < a[2][i]) swap(a[1][i],a[2][i]);
		}
		for(int i = 1;i <= 3;i++){
			for(int j = 1;j <= 3-i;j++){
				if(a[i][1] < a[i][2]) swap(a[i][1],a[i][2]);
			}
		}
		cout<<a[1][1] + a[1][2];
	}
	return 0;
}
