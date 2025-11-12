#include<bits/stdc++.h>
using namespace std;
const int N = 1e8;
string str = "",a;
int b[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for(int i = 0;i < a.size();i++){
		if(a[i] >= '0' && a[i] <= '9'){
			str += a[i];
		}
	}
	int len = str.size();
	for(int i = 0;i < len;i++){
		b[i] = str[i] - '0';
	}
	sort(b,b+len);
	while(len --){
		printf("%d",b[len]);
	}
	return 0;
}
