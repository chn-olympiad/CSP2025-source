#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m;
int Mypoint = 0;
int point[N];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >>point[i];
		if(i == 1){
			Mypoint = point[i];
		}
	}
	sort(point + 1, point + n * m + 1, cmp);
	int pos = 0;
	for(int i = 1; i <= n * m; i++){
		if(point[i] == Mypoint){
			pos = i;
			break;
		}
	}
	int h = pos / n;
	if(h * n != pos) h++;
	cout << h << " ";
	int l = 1;
	int From = (h - 1) * n + 1;
	int To = h * n;
	int temp = From + l - 1;
	while(point[temp] != Mypoint && temp >= From && temp <= To){
		l++;
		temp = From + l - 1;
	}
	if(h & 1){
		cout << l << endl;
	} else if(!(h & 1)){
		cout << n - l + 1 << endl;
	}
//	cout << l << endl;
//	if(h & 1){
//		int From = (h - 1) * n + 1;
//		int To = h * n;
//		int temp = From + l - 1;
//		while(point[temp] != Mypoint && temp >= From && temp <= To){
//			l++;
//		}
//		cout << l << endl;
//	}
//	if(!(h & 1)){
//		int From = (h - 1) * n + 1;
//		int To = h * n;
//		int temp = From + l - 1;
//		while(point[temp] != Mypoint && temp >= From && temp <= To){
//			l++;
//		}
//		cout << l << endl;
//	}
	return 0;
}
