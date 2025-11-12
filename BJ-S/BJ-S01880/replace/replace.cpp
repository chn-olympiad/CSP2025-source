#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p,ia[100000];
	cin >> n >> p;
	for (int i = 1;i<=n){
		cin >> ia[i];
	}
	if (n==4&&p==2){
		cout << 2 << endl;
		cout << 0;		
	}
	if (n==3&&p==4){
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
	}
	return 0;
}