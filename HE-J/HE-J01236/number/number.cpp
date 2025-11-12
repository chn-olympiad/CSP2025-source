
#include<bits/stdc++.h>
using namespace std;
#define _ short
char c;
_ a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	//input
	while(cin>>c){
		if(c>='0'&&c<='9'){
			a[c-'0']++;

		}
	}
	//number
	for(_ i=9;i>=0;i--){
		while(a[i]){
			printf("%d",i);
			a[i]--;
		}
	}
	return 0;
}

