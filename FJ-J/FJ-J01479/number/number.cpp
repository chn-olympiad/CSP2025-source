#include <bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin >> s;
	int Len=s.length();
	for (int i=0;i<Len;i++){
		if (int(s[i])>=48 && int(s[i])<=57){
			a[int(s[i])-48]++;
		}
	}
	for (int i=9;i>=0;i--){
		for (int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
