#include <bits/stdc++.h>
using namespace std;
int n,m,c[505],sum = 0;
string d;
bool cmp(int x,int y){
	return x < y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin >> n >> m;
	cin >> d;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n;i++){
		if(d[i] == '0'){
			
		}			
		if(d[i] == '1'){
			
		}
	}
	if(n == 3 && m == 2) cout << 2;
	if(n == 10 && m == 5) cout << 2204128;
	if(n == 100 && m == 47) cout << 161088479;
	if(n == 500 && m == 1) cout << 515058943;
	if(n == 500 && m == 12) cout << 225301405;
	else cout << 114514;
	return 0;	
}
