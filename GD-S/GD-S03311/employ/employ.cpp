#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
string s;
int c[505];
const int mod=998244353; 
namespace sub1{
	void sol(){
		long long ans=1;
		int tmp=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]<1)
				cnt++;
		}
		cnt=n-cnt;
		for(int i=1;i<=cnt;i++){
			ans=(ans*i)%mod;
//			cout<<ans<<endl;
		}
		for(int i=1;i<=n-cnt;i++)
			ans=(ans*i)%mod;
		cout<<ans<<endl; 
	}
}
namespace sub2{
	int p[505];
	void sol(){
		for(int i=1;i<=n;i++)
			p[i]=i;
		int ans=0;
		do{
			int nw=0;
			int res=0;
			for(int i=1;i<=n;i++){
				if(c[p[i]]<=nw){
					nw++;
				}
				else{
					if(s[i-1]=='0')
						nw++;
					else
						res++;
				}
			}
			if(res>=m)
				ans++;
			else{
				for(int i=1;i<=n;i++)
					cout<<p[i]<<' ';
				cout<<endl;
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<ans%mod<<endl;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	int fl=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			fl=1;
//	if(!fl){
//		sub1::sol();
//		return 0;
//	} 
	if(n<=20) 
		sub2::sol();
	else
		cout<<0<<endl;
	return 0;
}

