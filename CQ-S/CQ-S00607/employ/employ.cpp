#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=501,mod=998244353;
int T,n,m,ans,a[N],t[N];
ll fc[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s,fc[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i],t[i]=i;
	for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
	if(n<=10){
		do{
			int cnt=0,w=0;
			for(int i=1;i<=n;i++)if(a[t[i]]<=cnt||s[i-1]=='0')cnt++;
			else w++;
			ans+=w>=m;
		}while(next_permutation(t+1,t+n+1));
		cout<<ans;
	}else{
		cout<<fc[n];
	}
	return 0;
}
/*
我害怕，我惧怕，我畏缩，还胆寒 
我惊恐，我颤抖，我希望，又绝望 
*/
