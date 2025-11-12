#include<bits/stdc++.h>
using namespace std;
string s;
map<char,int> a;
int main(){
	freopen("nember.in","r",stdin);
	freopen("nember.out","w",stdout);
	char c;
	while((c=getchar())!=EOF){
		if(c>='0'&&c<='9'){
			a[c]++;
		}
	}
	for(char i='9';i>='0';i--){
		for(int j=1;j<=a[i];j++){
			putchar(i);
		}
	}
	return 0;
}
