#include<bits/stdc++.h>
using namespace std;
char s[1000000];
double j = 0;
double b[1000000];
bool cmp(int x,int y) {
    return x > y;
}
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin >> s;
	long long len = strlen(s);
	for(long long i = 0; i < len; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			b[(long long)j] = s[i] - '0';
			j++;
		}
	}
	sort(b  , b + (long long)j , cmp) ;
	for(long long i = 0; i < j; i++) {
		cout << b[i];
	}
	return 0;
}

