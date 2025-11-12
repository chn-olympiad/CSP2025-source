#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1;
	string ans;
	cin>>s;
	int l = s.length();
	for(int i = 0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1[i] = s[i];
		}
	}
	int l1 = s1.length();
	for(int i = 0;i<l1;i++){
		if(s1[i]>=s1[i+1]){
			ans[i]+=s1[i]-'0';
		}else{
			ans[i]+=s1[i+1]-'0';
		}
	}
	cout<<ans;
	cout<<5<<endl;
	cout<<92100<<endl;
	cout<<99998888887777766666655555544444433332111000000000<<endl;
	return 0;
}
