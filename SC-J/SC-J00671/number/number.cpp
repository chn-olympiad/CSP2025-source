#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long a[1000005];
long long cnt=0;
bool cmp(long long a,long long b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+1+cnt,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=cnt;i++){
		cout<<a[i]; 
	}
	return 0;
}