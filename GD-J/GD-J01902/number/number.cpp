#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
long long a[1000005],sum=0,max_=-1,b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	for(long long i=0;i<=n-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++sum]=s[i]-'0';
			if((s[i]-'0')>max_) max_=s[i]-'0';
			++b[(s[i]-'0')];
		}
	}
	for(long long i=max_;i>=0;i--){
		if(b[i]!=0){
			for(long long j=1;j<=b[i];j++) printf("%lld",i);
		}
	}
	return 0;
}
