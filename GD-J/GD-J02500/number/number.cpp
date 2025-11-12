#include <bits/stdc++.h>
using namespace std;
string s;
int l, id, sum[1000005];
bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.size();
	for (int i=0; i<l; i++){
		if (s[i]>='0' && s[i]<='9'){
			sum[++id] = s[i]-'0';
		}
	}
	sort(sum+1, sum+id+1, cmp);
	for (int i=1; i<=id; i++){
		cout << sum[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
