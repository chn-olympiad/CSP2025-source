#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    long long n,m,num0=0;
    cin>>n>>m;
    char s[505];
    for(int i=1;i<=n;i++){
    	cin>>s[i];
    	if(s[i]=='1')
    	num0++;
	}
	long long c[505];
    int p;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1){
		cout<<0;
		return 0;
	}
		long long num=1;
		long long ans=1;
		for(long long i=1;i<=m;i++){
			ans*=i;
			ans%=998244353;
		}
		if(num0==n){
			int num1=0;
		for(int i=1;i<=n;i++){
			if(c[i]==0)
			num1++;
		}
		if(num1>n-m)
		cout<<0;
		else{
		for(int i=1;i<=n;i++){
			num*=i;
			num=num%998244353;
		}
		cout<<num;
		}}
		else{
			cout<<ans;
		}
	return 0;
}
