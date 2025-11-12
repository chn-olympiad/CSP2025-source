#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end(),cmp);
	int i=0;
	while(i<s.size() && s[i]>='a' && s[i]<='z'){
		i++;
	}if(s[i]==0){
		cout<<0;
		return 0;
	}while(i<s.size()){
		cout<<s[i++];
	}
	return 0;
} 
