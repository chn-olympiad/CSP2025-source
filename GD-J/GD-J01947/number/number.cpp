#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
typedef long long ll;
int a[25];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	bool flag = 0;
	for(int i = 0;i < s.size();i++){
		char x = s[i];
		
		if(x >= '0' && x <= '9'){
			a[(x - '0')]++;	
			if(x > '0') flag = 1;
		}
	}
	
	if(!flag){
		cout << 0;
		return 0;
	}
	
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++){
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

