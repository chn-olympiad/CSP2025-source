#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
string s,s2="0";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<=s.size();i++){
		if(isdigit(s[i])){
			s2+=s[i];
		}
	}
	sort(s2.begin(),s2.end(),cmp);
	cout<<s2;
	//bydzhi hui zhe me xie le,wo zhen fu le,quan wang le
	return 0;
}
