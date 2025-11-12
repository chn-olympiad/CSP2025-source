#include <bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=0;
	cin >>s;
	string sn;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){
			sn.push_back(s[i]);
		}else if(s[i]=='0'){
			cnt++;
		}
	}
	if(sn.size()==0){
		cout <<0 <<endl;
		return 0;
	}else{
		sort(sn.begin(),sn.end(),cmp);
		cout <<sn;
		for(int i=0;i<cnt;i++) cout <<"0";
	}
	return 0;
}
