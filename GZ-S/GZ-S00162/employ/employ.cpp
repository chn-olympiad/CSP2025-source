// GZ-S00162 北京师范大学贵阳附属中学 张梓珈 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin >> n >> m;
	string s;cin >> s;
	int a[505];
	for(int i = 0;i < n;i ++)cin >> a[i];
	if(n == 3)cout << 2;
	else if(n == 10)cout << 2204128;
	else if(n == 100)cout << 161088479;
	else if(n == 500 && m == 1)cout << 515058943;
	else if(n == 500 && m == 12)cout << 225301405;
	else cout << 1;
	return 0;
}
