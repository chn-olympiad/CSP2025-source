#include<bits/stdc++.h>
using namespace std;
char s[1280000];
int nu[1280000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int v=1;
	cin >> s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		
		if('0'<=s[i] and '9'>=s[i] ){
			nu[v]=s[i]-'0';
			v++;
		}
	}
	sort(nu+1,nu+v+1);
	for(int i=v;i>=2;i--){
		cout<< nu[i];
	}
	return 0;
}
