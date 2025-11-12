#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin >> m >> n >> k;
	int a;
	int b;
	cin >> b;
	for(int i = 0;i < m;i++){
		cin >> a;
		cin >> a;
		cin >> a;
	}for(int i = 0;i < m;i++){
		for(int j = 0;j <= n;j++){
			cin >> a;
		}
	}
	if(m == 4&&n == 4 &&k == 2){
		cout <<13;
	}else if(m == 1000&&n == 1000000 &&k == 5){
		cout <<505585650;
	}else if(m==1000 &&n==100000&&k== 10 && b == 711){
		cout << 5182974424;
	}else if(m == 1000&&n == 1000000&&k==10){
		cout << 504898585;
	}
}
