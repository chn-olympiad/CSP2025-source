#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000005],cnt=0;
	cin >> s;
	for (int i=0;i<s.length();i++){
		if ((int)'0'<=(int)s[i] && (int)s[i]<=(int)'9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	for (int i=cnt-1;i>=0;i--){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
