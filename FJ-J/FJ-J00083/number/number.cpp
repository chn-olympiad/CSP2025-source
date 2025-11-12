#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int c[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt = 0;
	for(int i = 0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			c[cnt] = (int)s[i] - 48;
			cnt++;
		}
	}
	sort(c,c+cnt);
	for(int i = cnt-1;i>=0;i--){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

