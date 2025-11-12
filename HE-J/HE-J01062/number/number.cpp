#include <bits/stdc++.h>//100
using namespace std;
const int N = 1e6+5;
char s[N];
int t[15]; 
int cnt;
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  cin >> s;
  int len = strlen(s);
  for (int i=0;i<len;i++){
  	if (s[i]<='9'&&s[i]>='0'){
  	  t[s[i]-'0']++;
  	  cnt++;
	}
  }
  for (int i=9;i>=0;i--){
  	for (int j=1;j<=t[i];j++){
  	  cout<<i;
    }
  }
  return 0;
}
