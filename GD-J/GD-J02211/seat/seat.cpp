#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	const int SIZE = 1001;
	int sz[SIZE] = {0};
	 
	int n, m;
	cin >> n >> m;
	
	int a = 0;
	cin >> a;
	sz[0] = a;
	
	for(int i = 1; i < n * m; i ++){
		cin >> sz[i];
	}
	
	sort(sz, sz + (n * m));
	int rand = 0;
	
	for(int i = 0; i < (n * m); i ++){
		if(sz[i] == a){
			rand = i + 1;
			break;
		}
	}
	
	rand = (n * m) - rand + 1;
	
	//for(int i = 0; i < n * m; i ++){
	//	cout << sz[i] <<" ";
	//}
	
	//cout << rand << endl;
	
	int liet = ((rand - 1) / n) + 1;
	int hangs = rand - (n * (liet - 1));
	if(liet % 2 == 0){
		hangs = n - hangs + 1;
	}
	
	
	cout << liet << " " << hangs << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
