#include<bits/stdc++.h>
using namespace std;
int n,a[100010][4],s,t,b;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
			}
		}
		for(int i=1;i<=n;i++){		
			for(int j=1;j<=3;j++){
				for(int b=j+1;b<=n;b++){
					if(a[i][j]<a[i][b]){
						swap(a[i][j],a[i][b]);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		b+=a[i][1];
	}
	cout << b;
	return 0;
}
