#include <bits/stdc++.h>
#define int long long
using namespace std;
int b[1200006];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	int tot=0;
	while((a=getchar())!=10){
		if(a>=48&&a<=57){
			b[++tot]=a-48;
		}
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=tot;j++){
			if(b[j]==i){
				cout<<i;
			}
		}
	}
	return 0;
}

