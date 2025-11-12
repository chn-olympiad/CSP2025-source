#include <bits/stdc++.h>
using namespace std;
string s;
map <int,int> m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(('0'<=s[i])&&(s[i]<='9')){
			int k=s[i]-'0';
			m[k]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(m[i]!=0){
			cout <<i;
			m[i]--;
		}
	}
	return 0;
}

