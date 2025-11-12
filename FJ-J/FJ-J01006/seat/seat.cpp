#include<bits/stdc++.h>

using namespace std;

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int x = n * m;
	int arr[105];
	for(int i = 1;i <= x;i++){
		cin >> arr[i];
	}
	int r = arr[1];
	int nu;
	int ansx,ansy;
	sort(arr + 1,arr + x + 1,cmp);
	for(int i = 1;i <= x;i++){
		if(r == arr[i]){
			nu = i;
		}
	}
	if(nu % n == 0){
		ansx = nu / n;
		if((nu / n) % 2 == 1){
			ansy = n;
		}
		else{
			ansy = 1;
		}
		cout << ansx << " " << ansy;
		return 0;
	}
	ansx = nu / n + 1;
	if(ansx % 2 == 1){
		ansy = nu - (nu / n) * n;
	}
	else{
		ansy = n - (nu - (nu / n) * n) + 1;
	}
	cout << ansx << " " << ansy;
	
}

/*
a1  a(2n)  a(2n + 1)
a2  ...    a(2n + 2)
a3  an + 4 a(2n + 3)
a4  an + 3 a(2n + 4)
... an + 2 ...			
an  an + 1 a(3n)       ...  */
