#include<bits/stdc++.h>
using namespace std;
int num[30];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			num[x]++;
		}
	}int sum=9;
	while(sum>=0){
		for(int i=1;i<=num[sum];i++){
			cout<<sum;
		}
		sum--;
	}
	return 0;
} 
