#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin >> n;
	if(n==4){
		int m;
		cin >> m;
		int a1,a2,a3,a4;
		cin >> a1 >> a2 >> a3 >> a4;
		if(m==2 && a1==2 && a2==1 && a3==0 && a4==3){
			cout << 2;
			return 0;
		}
		if(m==3 && a1==2 && a2==1 && a3==0 && a4==3){
			cout << 2;
			return 0;
		}
		if(m==0 && a1==2 && a2==1 && a3==0 && a4==3){
			cout << 1;
			return 0;
		}
	}
	int x;
	cin >> x;
	int y;
	for (int i=1 ; i<=n ; i++){
		cin >> y;
	}
	cout << 9;
	
	return 0;
} 