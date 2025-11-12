#include<bits/stdc++.h>
#define ll long long
#define pll pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+8,mod=998244353;
inline void chkadd(int &x,int y){x=x+y<mod?x+y:x+y-mod;}
int f[1<<18][19];
int n,m,a[N];
string c;
void work(){
	cin>>n>>m>>c;
	for(int i=0;i<n;i++) cin>>a[i];
	f[0][0]=1;
	for(int s=1;s<(1<<n);s++){
		int cnt=0;
		for(int i=0;i<n;i++) if(s&(1<<i)) cnt++;
		for(int i=0;i<cnt;i++){
			for(int j=0;j<n;j++){
				if(s&(1<<j)){
					if(c[cnt-1]=='1'){
						if(cnt-1-i<a[j]) chkadd(f[s][i+1],f[s^(1<<j)][i]);
						else chkadd(f[s][i],f[s^(1<<j)][i]);
					}
					else chkadd(f[s][i],f[s^(1<<j)][i]);
				}
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) chkadd(ans,f[(1<<n)-1][i]);
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int T=1;//cin>>T;
	while(T--){
		work();
	}
	return 0;
}
