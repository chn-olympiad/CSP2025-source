#include<bits/stdc++.h>
using namespace std;
string s;int a;
char shu[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0 ; i < s.length(); i++){
		if(s[i] >= '0'&& s[i] <= '9'){
			shu[a] = s[i];
			a++;
		}	
	}
	sort(shu,shu+a);
	for(int i = a-1 ; i >= 0 ; i--){
		cout << shu[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
