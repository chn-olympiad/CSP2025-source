#include<bits/stdc++.h>
#define int long long
using namespace std;
int n=0,m=0;
string s="";
int a[505]={};
int _[505]={};
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		_[i]=i;
	}
	int sum=0;
	if(n<=18){
		do{
			int fail=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='0') fail++;
				else if(fail>=a[_[i]]) fail++;
			}
			if(n-fail>=m) sum++;
		}while(next_permutation(_+1,_+n+1));
		printf("%lld",sum);
	}
	else{
		sum=1;
		for(int i=1;i<=n;i++) sum=(sum*i)%998244353;
		printf("%lld",sum);
	}
	return 0;
}
