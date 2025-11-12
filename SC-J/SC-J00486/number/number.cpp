#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=s.size();i++){
		if(isdigit(s[i])){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+1+cnt);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}