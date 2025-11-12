#include<bits/stdc++.h>
using namespace std;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0 && s[i]-'0'<=9){
			num[s[i]-'0']++;
		}
	}
	int flag=0;
	for(int i=9;i>=0;i--){
		if(i==0 && flag==0){
			break;
		}
		while(num[i]>0){
			flag=1;
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}
