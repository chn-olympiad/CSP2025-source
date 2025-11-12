#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
ll n,m,a[505],b[505],tt,ru,ans,mod=998244353;
string s;
bool f;
int main(){
	IOS;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i],b[i]=i;
		if(a[i]==0)f=1;
	}
	if(n<=10){
		do{
			tt=ru=0;
			for(int i=1;i<=n;i++){
				if(ru>=m)break;
				if(tt>=a[b[i]]){tt++;continue;}
				if(s[i-1]=='0'){tt++;continue;}
				ru++;
			}
			if(ru>=m)ans=(ans+1)%mod;
		}while(next_permutation(b+1,b+1+n));
		cout<<ans;
		return 0;
	}
	if(m==1){
		if(f==0){
			ans=1;
			for(int i=1;i<=n;i++)
				ans=ans*i%mod;
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
