#include <bits/stdc++.h>
using namespace std;
int a[1000005];

bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int maxn = 0;
	int cnt = 0;
	int cnt1 = 0;
	for(int  i = 0;i < s.length();i++){
		if(s[i] >= '0'&&s[i] <= '9'){
			if(s[i] == '0') cnt++;
			else{cnt1++;
				a[cnt1] = s[i] - '0';
				maxn = max(maxn,a[cnt1]);
			}
		}
		}
	sort(a+1,a+1+cnt1,cmp);
	for(int i = 1;i <= cnt1;i++){
		cout << a[i];
	}
	for(int i = 1;i <= cnt;i++){
		cout << 0;
	}
	return 0;
 }