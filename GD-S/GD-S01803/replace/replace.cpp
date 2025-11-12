#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e4+5;
int n,qq,ne[N][N],k[N],z[N];
string a[N],b[N],aa,bb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>qq;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
		int k=-1;
		z[i]=a[i].size();
		ne[i][0]=-1;
		for(int j=1;j<z[i];++j){
			while(k!=-1&&a[j]!=a[k+1]) k=ne[i][k];
			if(a[j]==a[k+1]) ++k;
			ne[i][j]=k;
		}
	}
	while(qq--){
		cin>>aa>>bb;
		ll ans=0;
		int si=aa.size();
		fill(k+1,k+1+n,-1);
		for(int i=0;i<si;++i){
			for(int j=1;j<=n;++j){
				while(k[j]!=-1&&aa[i]!=a[j][k[j]+1]) k[j]=ne[i][k[j]];
				if(aa[i]==a[j][k[j]+1]) k[j]++;
				if(k[j]+1==z[j]) ans+=((aa.substr(0,i-z[j]+1)+b[j]+aa.substr(i+1))==bb),k[j]=ne[j][k[j]];
			}
		}
		cout<<ans<<'\n';
	}
}
