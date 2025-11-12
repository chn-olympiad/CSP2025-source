#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[10]={0},cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[s[i]-'0']++;
			cnt++;
		}
	}
	if(a[0]==cnt){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(long long j=0;j<a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
