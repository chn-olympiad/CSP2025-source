#include <bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
string s;
long long t[20],temp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i=i+1){
		if(s[i]>='0'&&s[i]<='9'){
			temp=s[i]-'0';
			t[temp]=t[temp]+1;
		}
	}
	for(int i=9;i>=0;i=i-1){
		while(t[i]!=0){
			cout<<i;
			t[i]=t[i]-1;
		}
	}
	return 0;
}
