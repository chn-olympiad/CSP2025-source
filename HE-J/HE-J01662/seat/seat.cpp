#include <bits/stdc++.h> 
using namespace std;

int a[105],b[105],n,m,i = 0,gui;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n*m;i++){
		cin >> a[i];
	}
	gui = a[0];
	sort(a,a+n*m);
	for(int i = 0;i<n*m;i++) b[i] = a[n*m-i-1];
	for(int i = 0;i<n*m;i++){
		if(gui == b[i]){
			gui = i;
			break;
		}
	}
	
	//上模拟！ 
	bool panding = 0;//0:下 1:上
	int q = 1,p = 1;//q列 p行 
	for(int i = 0;i<gui;i++){
		if(panding == 0){//向下 
			if(p == n){//最后一行 
				panding = 1;
				q++;
			}
			else p++;
		}
		else{//向上 
			if(p == 1){//第一行 
				panding = 0;
				q++;
			}
			else p--;
		}
	}
	cout << q << " " << p;
	return 0;
	/*盲猜有个样例是
	10 10
	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
	*/
}
