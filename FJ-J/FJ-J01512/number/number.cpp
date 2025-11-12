#include<iostream>
#include<string>
using namespace std;
int ans[15];
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'0';
		if(x>=0&&x<=9)ans[x]++;
	}
	for(int i=9;i>=0;i--)while(ans[i]--)cout<<i;
	return 0;
}
