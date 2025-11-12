#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,cnt,ans=1;
string s;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+1+n);
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=0)cnt++;
		}
		for(int i=1;i<=cnt;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}else if(m==n){
		cout<<1;
	}
}
