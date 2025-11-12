#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[10]={0,0,0,0,0,0,0,0,0,0};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int x=s[i]-'0';
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for (long long j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
