#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int ri=505,mo=998244353; 
int n,m,c[ri],ans=1,ans1;
bool vis[ri];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    int u=0;
    for(int i=1;i<=n;i++){
    	cin>>c[i];
    	if(c[i]==0) n--,u++;
	}
//	dfs(1,0,0);
	for(int i=m;i<=n;i++){
		ans1=u;
		for(int j=i;j<=n;j++){
			ans1=(ans1*j)%mo;
		}
		int fac=1;
		for(int j=1;j<=i;j++){
			fac=(fac*i)%mo;
		}
		ans1/=fac;
		ans=((ans+ans1)%mo+(ans1/u))%mo;
	}
	printf("%lld\n",ans%mo);
	return 0;
}
