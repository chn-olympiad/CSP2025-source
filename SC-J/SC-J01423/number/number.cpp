#include<bits/stdc++.h>
using namespace std;
int a[9000000];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long j=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+s.size(),cmp);
	for(long long i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}