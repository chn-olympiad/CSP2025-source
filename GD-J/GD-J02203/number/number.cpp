#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	string s;
	vector<int> a;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'<10){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
