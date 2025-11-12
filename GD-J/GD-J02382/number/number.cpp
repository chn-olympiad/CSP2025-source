#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(char s1,char s2){
	return s1>s2;
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string s,ans;cin>>s;
	for(int i=0;i<s.size();i++)if(isdigit(s[i]))ans.push_back(s[i]);
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
	return 0;
} 
