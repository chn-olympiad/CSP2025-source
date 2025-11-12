#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(LL i=0;i<s.size();i++){
		if(s[i]>='a'){
			s.erase(i,1);
			i--;
		}
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}
