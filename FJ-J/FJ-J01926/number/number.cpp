#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	vector<char>a;
	cin>>s;
	if(s.size()==1){
		cout<<s<<endl;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a.push_back(s[i]);
		}
	}
	if(a.size()==1){
		printf("%c\n",a[0]);
		return 0;
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
		printf("%c",a[i]);
	}
	return 0;
} 

