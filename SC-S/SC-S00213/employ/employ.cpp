#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
long long n,m,k,ans=1,res,p[505],idd[505],ke,bk,ze;
long long c[501][501];
char s[1000];
bool flag1=true;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') flag1=false;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		idd[i]=i;
	}
	if(n<=10){
		do{
			bk=0;
			ke=0;
			for(int i=1;i<=n;i++){
				if(p[idd[i]]<=bk){
					bk++;
					continue;
				}
				if(s[i]=='0'){
					bk++;
				}
				else{
					ke++;
				}
				
			}
			if(ke>=m) res++;
		}while(next_permutation(idd+1,idd+n+1));
		cout<<res<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(p[i]==0) ze++;
	}
	if(n-ze<m) cout<<"0"<<"\n";
	else if(flag1){
		for(int i=1;i<=n-ze;i++){
			ans=ans*i%MOD;
		}
		for(int i=1;i<=ze;i++){
			ans=ans*i%MOD;
		}
		cout<<ans<<"\n";
	}
	return 0;
}