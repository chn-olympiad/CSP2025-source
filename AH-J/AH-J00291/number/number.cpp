#include<bits/stdc++.h>
using namespace std;
string s,str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sort(s.begin(),s.end());
	long long len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			str+=s[i];
		}
		else break;
	}
	reverse(str.begin(),str.end());
	cout<<str;
	return 0;
}
