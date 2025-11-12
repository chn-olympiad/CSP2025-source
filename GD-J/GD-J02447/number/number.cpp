#include <bits/stdc++.h>
using namespace std;
char a[1100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(a,1001000);
	int lens=strlen(a);
	for(int m=9;m>=0;m--){
		for(int i=0;i<lens;i++){
			if(a[i]-'0'==m) cout<<a[i];
		}
	}
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}
