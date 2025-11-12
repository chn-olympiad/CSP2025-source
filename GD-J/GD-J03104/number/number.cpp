#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s,s2;
	cin>>s;
	for(int i=0,l=s.size();i<l;i++){
		if(s[i]>='0' && s[i]<='9')s2+=s[i];
	}
	sort(s2.begin(),s2.end(),cmp);
	cout<<s2;
	return 0;
} 
