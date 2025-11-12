#include<bits/stdc++.h>
using namespace std;
string s;
long long ans,a[1000007],len;
bool cmp(long long a,long long b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i ++){
		if (s[i] >= '0' && s[i] <= '9'){
			a[++len] = (int)(s[i] - '0');
		}
	}
	sort(a+1,a+len+1,cmp);
	for(int i = 1;i <= len;i ++) cout << a[i];
	return 0;
}
