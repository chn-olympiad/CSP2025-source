#include<bits/stdc++.h>
using namespace std;
int Jml[20]={0};
int main(){
	freopen("number1.in","r",stdin);
	freopen("number1.ans","w",stdout);
	ios::sync_with_stdio,cin.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if((s[i]>='0')&&(s[i]<='9'))Jml[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(Jml[i]--){
			cout<<i;
		}
	}
}