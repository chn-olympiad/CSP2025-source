#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=1e4+10;
int f[N],g[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ull n,m;cin>>n>>m;
	string s;cin>>s;
	g[1]=1;
	for(int i=2;i<=n;i++){
		g[i]=g[i]*g[i-1]%998244353;
	}
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	
	sort(f+1,f+n+1);
	int t=n;ull ans=1,sum=0,cnt=0;
	for(int i=1;i<=t;i++){
		if(f[i]==cnt)n--;
		else {
			map <int,int>mp;
			int x=min(m-cnt,n);
			for(int j=1;j<=min(m-cnt,n);j++){
				if(mp[i+j-1]==0){
					mp[i+j-1]=1;
				}
				else x--;
			}
			sum=(sum+g[x+1])%998244353;cnt++;
			ans=1;
		}
	}
	cout<<sum<<endl;
	return 0;
}
