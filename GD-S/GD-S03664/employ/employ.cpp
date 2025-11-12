#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500+10,mod=998244353;
string st;
ll f[1<<18][19],c[N];
ll n,m,res;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>st;st="#"+st;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	f[0][0]=1;
	for(int s=1;s<(1<<n);s++){
		int cnt=0;
		for(int j=s;j;j-=(j&-j)) cnt++;
//		cout<<s<<" "<<cnt<<"\n";
		for(int k=0;k<=cnt;k++){
			for(int j=s;j;j-=(j&-j)){
				int x=log2(j&-j)+1;
//				cout<<"#"<<j-(j&-j)<<" "<<(j&-j)<<" "<<x<<"\n";
				if(cnt-1-k>=c[x]||st[cnt]=='0')
					f[s][k]=(f[s][k]+f[j-(j&-j)][k])%mod;
				else if(k) 
					f[s][k]=(f[s][k]+f[j-(j&-j)][k-1])%mod;
			}
//			cout<<s<<" "<<k<<" "<<f[s][k]<<"\n";
			if(k>=m && f[s][k]) {
				cout<<s<<" "<<k<<" "<<f[s][k]<<"\n";
				for(int j=s;j;j-=(j&-j)) cout<<log2(j&-j)+1<<" ";
				cout<<"\n";
				res=(res+f[s][k])%mod;
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}

