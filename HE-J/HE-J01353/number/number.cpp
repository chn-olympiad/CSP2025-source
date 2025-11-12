#include<bits/stdc++.h>
using namespace std;
long long t[10000],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long i=0;i<=s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			t[cnt]=s[i]-48;
		}
	}
	int a[9]={};
	for(long long i=1;i<=cnt;i++)
		a[t[i]]++;
	for(long long i=9;i>=0;i--){
		if(a[i]!=0){
			for(long long j=1;j<=a[i];j++)
				cout<<i;
		}
	}
	return 0;
}
