#include<iostream>
#include<cstdio>
int a[101], k=0;
using namespace std;
void bubble(){
	for(int i=0; i<k; i++){
		for(int j=k; j>0; j--){
			if(a[i]>=a[j-1]){
				(a[i], i[j-1]);
			}
		}
	}
}
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m, n;
	cin >> m >> n;
	if(m<=1&&n<=1){
		cout << 1 << " " << 1;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[i];
			k++;
		}
	}
	bubble();
	for(int i=0; i<k; i++){\
	    cout << a[i] << " ";
	}
	return 0;
} 
