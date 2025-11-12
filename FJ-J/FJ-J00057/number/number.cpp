#include<bits/stdc++.h>
using namespace std;
string s,x;
int a[10],len;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']++;
	}
	for(int i=9;i>0;i--){
		while(a[i]--)x+=(i+'0');
	}
	if(x.size()==0)cout<<"0";
	else{
		while(a[0]--)x+='0';
		cout<<x;
	}
	return 0;
}
