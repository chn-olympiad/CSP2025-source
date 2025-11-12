#include<bits/stdc++.h>
using namespace std;
string s;
long long tong[1000010],cnt = 0;
bool cmp(long long a,long long b){return a > b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			tong[++cnt] = int(s[i] - 48);	
		}
	}
	sort(tong + 1,tong + cnt + 1,cmp);
	for(int i = 1;i <= cnt;i++){
		cout << tong[i];
	}
	return 0;
}
