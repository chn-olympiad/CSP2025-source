#include <bits/stdc++.h>
using namespace std;
#define FILE_OPEN
pair<int , int> a[13];
int main(){
	#ifdef FILE_OPEN
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	#endif
	int n , m = 0;
	cin >> n >> m;
	string h;
	cin >> h;
	if(n <= 12){
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i].second;
			a[i].first = i;
		}
		sort(a + 1 , a + n + 1);
		int tt = 0;
		do{
			int sum = 0 , in = 0;
			for(int j = 1 ; j <= n; j ++){
//			cout << h << "\n";
				if(h[j - 1] == '0'){
					sum ++;
				}
				else{
//					cout << h[j] << " < " << sum << " ";
					if(sum >= a[j].second)sum ++;
					else in ++;
				}
			}
			tt += (in >= m);
//			for(int j = 1 ; j <= n ; j ++)cout << a[j] << " ";
//			cout << in << "\n";
		}while(next_permutation(a + 1 , a + n + 1));
		cout << tt ;
	}
	else{
		cout << 0;
	}
	return 0;
}
/*
11 5
11011110110
6 0 4 2 1 2 5 4 3 3 4
*/
