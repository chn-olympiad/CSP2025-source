#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=525;
const ll mod=998244353;
ll n,m,sum,c[N],ans,f[25+(1<<18)][20];
string s;
bool A=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			A=0;
		}else sum++;
	}
	if(n-sum<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];	
	}
	if(A){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*2)%mod;
		}
		cout<<ans;
	}
	else if(n<=18){
		f[0][0]=1;
		for(int sj=0;sj<(1<<n);sj++){
			bitset<20> _2(sj);
			int num=_2.count();
			for(int i=0;i<=num;i++){
				for(int j=1;j<=n;j++){
					if(!_2[j-1]){
						if(s[num+1]=='0'||num-i>=c[j]){
							f[sj+(1<<(j-1))][i]+=f[sj][i];
							f[sj+(1<<(j-1))][i]%=mod;
						} 
						else{
							f[sj+(1<<(j-1))][i+1]+=f[sj][i];
							f[sj+(1<<(j-1))][i+1]%=mod;
						} 
					}
				}
			}
		}
		for(int i=m;i<=n;i++){
			ans+=f[(1<<n)-1][i];
			ans%=mod;
		}
		cout<<ans;
	}
	return 0;
}