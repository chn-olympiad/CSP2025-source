#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int c[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n >> m >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	sort(c + 1,c + n + 1);
	int num = 0;
	for(int i =1;i <= n;i++){
		if(c[i] >= num){
			num++;
		} 
	}
	cout << num;
	return 0;
}
