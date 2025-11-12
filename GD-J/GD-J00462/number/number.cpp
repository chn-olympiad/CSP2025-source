#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000010];
bool cmp (int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int cnt=1;
	for (int i=1;i<=s.size();i++){
		if (s[i-1]>='0'&&s[i-1]<='9'){
			a[cnt++]=s[i-1]-'0';
		}
	}
	sort(a+1,a+cnt,cmp);
	for (int i=1;i<cnt;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
