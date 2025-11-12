#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000007],sum;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++sum] = s[i] - '0';
		}
	}
	sort(a + 1,a + 1 + sum,cmp);
	for(int i = 1;i <= sum;i++){
		cout << a[i];
	}
	return 0;
}
