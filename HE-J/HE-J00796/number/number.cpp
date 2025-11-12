#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string str;
	cin>>str;
	string s;
	for(int i=0; i<str.size(); i++){
		if(isdigit(str[i])){
			s+=str[i];
		}
	}
	
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	
	cout<<s<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
