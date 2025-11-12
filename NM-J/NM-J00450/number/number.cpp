#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
  string s;
  vector<char> MAX;
  cin>>s;
  sort(s.begin(),s.end());
  if(s.size()==1){
    cout<<s;
    return 0;
  }
  for(int i=s.size();i>=0;i--){
  	if(isdigit(s[i])){
        cout<<s[i];
	  }
  }
  return 0;
  }

