#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,b=0,m=0,y=0;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			m=a[j];
			b+=a[j];
			if(b>=m*2){
				y++;
			}
		}
	}
	cout << y;
	return 0;
}
