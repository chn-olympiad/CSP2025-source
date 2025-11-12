#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> nms;

bool isnm(char c){
	if(c>='a'&&c<='z'){
		return false;
	}
	if(c>='A'&&c<='Z'){
		return false;
	}
	return true;
}
int tint(char c){
	return c-'0';
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if(isnm(s[i])){
			nms.push_back(tint(s[i]));
		
		}
	}
	sort(nms.begin(),nms.end(),cmp);
	
	for(int i=0;i<nms.size();i++){
		cout<<nms[i];
	}
}
