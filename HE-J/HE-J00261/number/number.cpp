#include <bits/stdc++.h>
using namespace std;
int len2;
int main(){
	string s;
	cin>>s;
	vector<int> v;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			len2++;
			v.push_back(s[i]-'0');
		}
	}
	for(int i=0;i<len2;i++){
		for(int j=i+1;j<len2;j++){
			if(v[i]<v[j]){
				int n=v[i];
				v[i]=v[j];
				v[j]=n;
			}
		}
	}
	for(int i=0;i<len2;i++){
		cout<<v[i];
	}
	return 0;
}
