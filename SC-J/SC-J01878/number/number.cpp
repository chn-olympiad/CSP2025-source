#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int num[1000005],top;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			num[++top]=s[i]-'0';
		}
	}
	sort(num+1,num+1+top);
	for(int i=top;i>=1;i--){
		cout<<num[i];
	}
	
	return 0;
}