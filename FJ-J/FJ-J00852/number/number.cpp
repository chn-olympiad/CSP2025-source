#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[1000005]={},cnt=1;
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt+1);
	for(long long i=cnt;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
