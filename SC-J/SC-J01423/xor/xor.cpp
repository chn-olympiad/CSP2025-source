#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
string s[1000000];
long long n,k;
string er(long long n){
	string k="",ans="";
	while(n>0){
		k=k+(char)(n%2+'0');
		n/=2;
	}
	for(int i=k.size()-1;i>=0;i--){
		ans+=k[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=er(a[i]);
    }
    long long number0=0,number1=0;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<s[i].size();j++){
    		if(s[i][j]!='0') number1++;
    		else number0++;
		}
	}
	cout<<abs((abs(number1-number0)^k)-1);
	return 0;
}