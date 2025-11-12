#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010],c=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			num[c]=int(s[i]-'0');
			c++;
		}
	}
	sort(num+1,num+c+1);
	for(int i=c;i>1;i--){
		cout<<num[i];
	}
	return 0;
}
