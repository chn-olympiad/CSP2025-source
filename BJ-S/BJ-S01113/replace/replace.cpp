#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],t1[N],t2[N];
void solve1(){
	for(int i=1;i<=q;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			int p=s1[j].size();
			for(int l=0;l+p-1<(int)t1[i].size();l++){
			//	cout<<i<<" "<<j<<" "<<l<<" "<<t1[i].substr(l,p)<<" "<<t2[i].substr(l,p)<<'\n';
				if(t1[i].substr(l,p)==s1[j] && t1[i].substr(0,l)+s2[j]+t1[i].substr(l+p,t1[i].size()-l-p+1)==t2[i]) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
const int M=5e6;
int h[10000005];
void solve2(){
	for(int i=1;i<=n;i++){
		int u=s1[i].find('b'),v=s2[i].find('b');
		h[u-v+M]++;
	}
	for(int i=1;i<=q;i++){
		int u=t1[i].find('b'),v=t2[i].find('b');
		cout<<h[u-v+M]<<'\n';
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		sum+=s1[i].size()+s2[i].size();
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	if(sum<=2000) solve1();
	else solve2();
	return 0;
}