#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+4;

int n, q;
char strs[N][2], ques[N][2];

int inline read(){
	int x=0, f=1;
	char ch = getchar();
	if(ch<'0' || ch>'9'){
		if(ch == '-'){
			f = -1;
			ch = getchar();
		}
	}
	if(ch>='0' && ch <='9'){
		x = x*10 + ch -'0';
		ch = getchar();
	}
	return x*f;
}

int main(){
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> strs[i][0] >> strs[i][1];
	}
	for(int i=1; i<=q; i++){
		cin >> ques[i][0] >> ques[i][1];
	}
	
	
	
	
	
	return 0;
}
