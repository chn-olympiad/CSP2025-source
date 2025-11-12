#include<bits/stdc++.h>
using namespace std;
string s;
int a[11];
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>> s;
	for(int i=0;i<s.size();i++){
		int f=s[i]-'0';
		if(f<=9&&f>=0){
			a[f]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			printf("%d",i);
			a[i]--;
		}
	}
	
	
	return 0;
}
