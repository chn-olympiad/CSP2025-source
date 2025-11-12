#include<bits/stdc++.h>
using namespace std;
const long long N=1e9+37,p=127;
int n,m;
int len[200010];
unsigned long long q[5000010];
long long q2[5000010];
unsigned long long a[5000010],b[5000010];
long long a2[5000010],b2[5000010];
unsigned long long u[200010],v[200010];
long long u2[200010],v2[200010];
bool vis[5000010],vis2[5000010];
string s,t;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	q[0]=1;
	q2[0]=1;
	for(int i=1;i<=5000000;i++){
		q[i]=q[i-1]*p;
		q2[i]=q2[i-1]*p%N;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		len[i]=s.size();
		for(int j=0;j<len[i];j++){
			u[i]=u[i]*p+s[j];
			u2[i]=(u2[i]*p%N+s[j])%N;
			v[i]=v[i]*p+t[j];
			v2[i]=(v2[i]*p%N+t[j])%N;
		}
	}
	while(m--){
		cin>>s>>t;
		int k=s.size();
		s=' '+s;
		t=' '+t;
		for(int i=0;i<=k+1;i++){
			vis[i]=0;
			vis2[i]=0;
		}
		vis[0]=1;
		for(int i=1;i<=k;i++){
			if(s[i]!=t[i]) break;
			vis[i]=1;
		}
		vis2[k+1]=1;
		for(int i=k;i>=1;i--){
			if(s[i]!=t[i]) break;
			vis2[i]=1;
		}
		int cnt=0;
		for(int i=1;i<=k;i++){
			a[i]=a[i-1]*p+s[i];
			a2[i]=(a2[i-1]*p%N+s[i])%N;
			b[i]=b[i-1]*p+t[i];
			b2[i]=(b2[i-1]*p%N+t[i])%N;
			for(int j=1;j<=n;j++){
				if(len[j]>i) continue;
				if(u[j]==a[i]-a[i-len[j]]*q[len[j]]&&v[j]==b[i]-b[i-len[j]]*q[len[j]]&&vis[i-len[j]]&&vis2[i+1]){
					++cnt;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
