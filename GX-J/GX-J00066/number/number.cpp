#include<bits/stdc++.h>
using namespace std;
string s;
int sum[10]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int num=s[i]-'0';
			sum[num]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<sum[i];j++){
			cout<<i;
		}
	}
	return 0;
}
