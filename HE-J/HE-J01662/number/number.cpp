#include <bits/stdc++.h> 
using namespace std;

string a;
int b[1000005],n = 0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i = 0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9') b[n++] = a[i]-'0';
	}
	sort(b,b+n);
	for(int i = n-1;i>=0;i--){
		cout << b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Ë®Ìâ 
