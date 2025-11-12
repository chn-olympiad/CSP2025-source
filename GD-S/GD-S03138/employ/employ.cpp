#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=18,P=998244353;
int n,m,c[N],f[N][1<<N],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s;
	if(n>18){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++)cin>>c[i];
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int t=i,l=-1;
		while(t)l+=t%2,t/=2;
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				for(int k=0;k<n;k++){
					if(k>=c[j]||s[l]=='0')(f[k+1][i]+=f[k][i-(1<<j)])%=P;
					else (f[k][i]+=f[k][i-(1<<j)])%=P;
				}
			}
		}
	}
	for(int i=m;i<=n;i++)(ans+=f[n-i][(1<<n)-1])%=P;
	cout<<ans;
}
