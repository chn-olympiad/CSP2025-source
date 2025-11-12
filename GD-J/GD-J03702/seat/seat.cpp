#include<iostream>
#include<algorithm>
using namespace std;

int s[110]={0};

bool cmp(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a = n * m - 1;
	int xm;
	cin >> xm;
	s[0] = xm;
	for(int i=1; i<=a; i++){
		cin >> s[i];
	}
	sort(s, s + a + 1, cmp);
//	for(int i=0; i<a+1; i++){
//		printf("%d ", s[i]);
//	}
	for(int i = 1, j = 1, as = 1; ; ){
		if(as % n != 0){
			if(as / n % 2 == 0){
				j ++;
//				cout << "++\n";
			} else {
				j --;
//				cout << "--\n";
			}
		} else {
			i ++;
//			cout << "ii\n";
		}
		if(s[as] == xm){
			cout << i << " " << j;
			return 0;
		}
		as ++;
	}
	return 0;
}//98 99 100 97
//100 99 98 97
