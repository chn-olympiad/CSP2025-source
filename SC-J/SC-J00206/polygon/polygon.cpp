#include<bits/stdc++.h>
using namespace std;
int n,a[5005];//以WHH之力击碎T4 
long long s[5][5005],ans,da,f=5000;
const long long M=998244353;
const long long Mo=998244353000;
long long cc(int x){
	long long fs=1;
	for(int i=1;i<=x;i++){
		fs*=2;
		fs%=Mo;
	}
	return fs;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		da=max(da,da+a[i]);
	}
	da=min(da,f);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=da;j++){
			if(j==0) s[2][j]=cc(i)-1;
			else{
				if(a[i]>j) s[2][j]=s[1][0]+1+s[1][j];
				else s[2][j]=s[1][j-a[i]]+s[1][j];
			}
			s[2][j]%=Mo;
		}
		if(i>=3){
			ans+=s[1][a[i]];
			ans%=M;
		}
		for(int j=0;j<=da;j++) s[1][j]=s[2][j];
	}
	cout<<ans;
	return 0;
}