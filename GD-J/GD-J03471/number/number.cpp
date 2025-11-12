#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s="";
	vector<int> num;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			num.push_back(int(s[i])-int('0'));
		}
	}
	sort(num.begin(),num.end());
	for(int i=num.size()-1;i>=0;i--){
		cout<<num[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
