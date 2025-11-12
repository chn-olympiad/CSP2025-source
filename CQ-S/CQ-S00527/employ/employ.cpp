#include<bits/stdc++.h>
#define M 998244353
using namespace std;
long long n,m,k,a,b,ans=1,c[505],ek[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		k+=(s[i-1]=='1');
		ans=ans*i%M;
		ek[i]=i;
	}
	if(n<=10){
		ans=0;
		do{
			a=b=0;
			for(int i=1;i<=n;i++){
				if(s[i-1]=='0'){
					b++;continue;
				}else{
					if(b>=c[ek[i]]){
						b++;continue;
					}else a++;
				}
			}
			if(a>=m)ans++;
		}while(next_permutation(ek+1,ek+n+1));
	}
	cout<<ans;
	return 0;
}
