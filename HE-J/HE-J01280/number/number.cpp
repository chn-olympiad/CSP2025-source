#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int len=s.length(),k=0;
	vector<int > a;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'<=9&&s[i]-'0'>=0){
			a.push_back(int(s[i]-'0'));	
			k++;	
		}
	}
	sort(a.begin()+0,a.end()-0);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
	

