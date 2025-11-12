#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],n=0;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[n++]=s[i]-'0';
		}
	}
	sort(num,num+n);
	for(int i=n-1;i>=0;i--){
		cout<<num[i]; 
	}
	return 0;
}
