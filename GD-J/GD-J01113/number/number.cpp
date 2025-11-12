#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const char &i,const char &j){
	return i>j;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	string ans;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			ans+=s[i];
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
	return 0;
} 
