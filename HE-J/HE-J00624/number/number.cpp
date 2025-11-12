#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1="";
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>47&&s[i]<58){
			s1+=s[i];
		}
	}
	
	sort(s1.begin(),s1.end()) ;
	for(int i=s1.size()-1;i>-1;i--){
		cout << s1[i];
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
