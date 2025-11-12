#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+3;
string str;
int p[N],cnt;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	int n = str.size();
	str = " " + str;
	for(int i = 1;i <= n;i++){
		if(isdigit(str[i])) p[++cnt] = str[i]-'0';
	}
	sort(p+1,p+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++) cout << p[i];
	return 0;
}