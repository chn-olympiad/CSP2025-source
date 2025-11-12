#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],num[505],sum,f;
long long ans=0;
string s;
bool flag=0;
int main(){	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//no sir!!!!!!!!!!!!!!!!!!!!!!!
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for (int i=1;i<=n;i++) cin>>c[i];
	for (int i=1;i<=n;i++){
		if (s[i]!=1) flag=1;
	}
	if (flag==0){
		ans=1;
		for (int i=2;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	for (int i=1;i<=n;i++) num[i]=i;
	do{
		sum=f=0;
		for (int i=1;i<=n;i++){
			if (f>=c[num[i]]){
				f++;
				continue;
			}
			if (s[i]=='1'){
				sum++;
			}
			else{
				f++;
			}
		}
		if (sum>=m) ans++;
		ans%=mod;
	}while(next_permutation(num+1,num+1+n));
	cout<<ans;
	return 0;
}
