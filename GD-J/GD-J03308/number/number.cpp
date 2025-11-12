#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.size(),b = 0;
	for(int i = 0; i < len; i++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[b] = int(s[i] - '0');
			b++;
		}
	}
	sort(a,a+b,cmp);
	for(int i = 0; i < b; i++){
		cout << a[i];
	}
	return 0;
} 
