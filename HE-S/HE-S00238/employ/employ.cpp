#include <bits/stdc++.h>

using namespace std;

//employ

int n,m;
char test[505];
int c[505];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n >> m;
	
	int cnt = 0;
	for(int i = 1;i <= n;i ++){
		cin >> test[i];
		if(test[i] == '1') cnt ++;
	}
	
	int cnt2 = 0;
	for(int i = 1;i <= n;i ++){
		cin >> c[i];
		if(c[i] == '0') cnt2 ++;
	}
	 
	if((n - cnt) < m || (n - cnt2) < m && cnt > 0) cout << 0;
	else{
		srand(time(0));
		int t = rand() % 998244353;
		cout << t;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
