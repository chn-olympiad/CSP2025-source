#include<iostream>
using namespace std;
string a;
int s[40],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	l = a.length();
	for(int i = 0;i < l;i++){
		s[int(a[i]-48)]++;
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 0;j < s[i];j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
