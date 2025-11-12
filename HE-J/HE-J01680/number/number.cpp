#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]<='9'&&'0'<=str[i]){
				a.push_back(str[i]-'0');	
		}
	}
sort(a.begin(),a.end(),greater<int>());
for(int i=0;i<a.size();i++){
	cout<<a[i];
}
	return 0;
}
