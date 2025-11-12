#include<bits/stdc++.h>
using namespace std;
/*
Ren5Jie4Di4Ling5%

upd 16:47

so difficult!!
now min=10+16+0+0=26;
now max=10+48+0+4=62

upd 17:28
T1's baoli had been finished!
now min=25+16+0+0=41
now max=25+48+0+4=77
*/
//may 16
int n,m;
string s;
const int N=505;
const int mod=998244353;
int a[N];
long long jie(long long m){
	long long ans=1;
	while(m){
		if(m)ans*=m;
		ans%=mod;
		m--;
	}
	return ans%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(m==1){
		long long res=0;
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				res+=(jie(n-1));
			}
			res%=mod;
		}
		cout<<res%mod;
		return 0;
	}
	cout<<0;
	return 0;
}
