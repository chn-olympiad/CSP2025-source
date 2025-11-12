#include <bits/stdc++.h>
using namespace std;
string s;
bool cmp(int a,int b){
      return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	vector<int>num;
	for(size_t i=0;i<s.size();i++){
		if(s[i]>=48 && s[i]<=57){
			num.push_back(s[i]-48);
		}
	}
	sort(num.begin(),num.end(),cmp);
      for(auto v:num){
            cout<<v;
      }
    return 0;
}
