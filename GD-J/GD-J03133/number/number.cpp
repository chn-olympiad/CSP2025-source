#include<bits/stdc++.h>
using namespace std;
string s;
long long num[1100000],len,len2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0' and s[i]<='9'){
			len2++;
			num[len2]=s[i]-'0';
		}
	}
	if(len2==0){
		cout<<0;
	}else{
		sort(num+1,num+1+len2);
		for(long long i=len2;i>=1;i--){
			cout<<num[i];
		}
	}
	return 0; 
} 
