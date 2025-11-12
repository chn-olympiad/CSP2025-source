#include<bits/stdc++.h>
using namespace std;
string str;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	str='0'+str;
	int len=str.size();
	for(int i=1;i<=len;i++){
		if(str[i]>='0'&&str[i]<='9')t[str[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++)cout<<i;
	}
	return 0;
}
