#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+10;
int b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]>0){
			cout << i;
			b[i]--;
		} 
	}
	return 0;
}

