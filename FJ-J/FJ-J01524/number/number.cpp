#include<bits/stdc++.h>
using namespace std;
char c[1000005];
int l,a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> c;
	l=strlen(c);
	for(int i=0;i<l;i++){
		if(c[i]>='0'&&c[i]<='9'){
			a[c[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout << i;
		}
	}
	return 0;
}
