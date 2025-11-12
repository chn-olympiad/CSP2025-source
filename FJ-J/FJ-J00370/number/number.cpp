#include <bits/stdc++.h>
using namespace std;

char s[100005];
int t[15];
int lens;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	
	scanf("%s",s + 1);
	lens = strlen(s + 1);
	int sf = 0;
	for(int i = 1;i <= lens;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			t[s[i] - '0']++;
			if(s[i] != '0')sf = 1;
		}
	}
	if(sf == 0) cout << 0;
	else{
		for(int i = 9;i >= 0;i--){
			for(int j = 1;j <= t[i];j++){
				cout << i;
			}
		}		
	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
