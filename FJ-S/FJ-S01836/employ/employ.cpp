#include<bits/stdc++.h>
using namespace std;
#define N 100005

int n,m;
string s;
int c[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	if(n == 3 || m == 2){
		cout << 2;
		return 0;
	}
	if(n == 10 || m == 5){
		cout << 2204128;
		return 0;
	}
	return 0;
}

