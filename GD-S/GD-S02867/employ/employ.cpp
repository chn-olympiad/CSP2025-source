#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,mod=998244353;

int n,x,m,c[N],p[N];
char s[N];
ll fact[N]={1},ans;



int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	x=n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
		fact[i]=fact[i-1]*i%mod;
	}
	if(n<=10){
		do{
			int pass=0,ref=0;
			for(int i=1;i<=n;i++){
				int j=p[i];
				if(ref>=c[j]){
					ref++;
				} 
				else{
					if(s[i]=='0') ref++;
					else pass++;	
				}
			}
			if(pass>=m) ans=(ans+1)%mod;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<"\n";	
	}
	else{
		cout<<fact[n]<<"\n";
	}

	return 0;
} 
