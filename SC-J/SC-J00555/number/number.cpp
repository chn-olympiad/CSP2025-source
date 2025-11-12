#include<bits/stdc++.h>
using namespace std;
//计数，统计0~9的个数，从9~0输出，有多少个就输出多少个
int num[15]={0};
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=num[i];j>=1;j--){
			cout<<i;
		}
	}
	return 0;
}