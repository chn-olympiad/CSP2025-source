#include<bits/stdc++.h>
using namespace std;
string s;
int f;
vector<int>v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
			if((int)s[i]-'0')f=1;
		}
	}
	sort(v.begin(),v.end(),greater<int>());
	if(f){
		for(int x:v)printf("%d",x);
	}else cout<<0;
	return 0;
} 
