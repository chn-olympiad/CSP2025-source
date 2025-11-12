#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	vector<int> a;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}

	for(int i=1;i<a.size();i++){
		for(int j=0;j<a.size()-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
}
