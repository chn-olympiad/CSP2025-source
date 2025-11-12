#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,L=5e6+5;
const int base=233;
int n,q;
int len[N];
ll ans;
ll pw[L],h1[L],h2[L],th1[L],th2[L];
string s1,s2,t1,t2;
inline ll get_h(ll th[],ll l,ll r){
	return th[r]-th[l-1]*pw[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	pw[0]=1;
	for(int i=1;i<=L-5;i++)pw[i]=pw[i-1]*base;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++)h1[i]=h1[i]*base+(s1[j]-'a'+1);
		for(int j=0;j<s2.size();j++)h2[i]=h2[i]*base+(s2[j]-'a'+1);
		len[i]=s1.size();
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";continue;
		}
		int siz=t1.size();
		t1="#"+t1,t2="#"+t2;
		int l=0,r=0;
		for(int j=1;j<=siz;j++){
			th1[j]=th1[j-1]*base+(t1[j]-'a'+1);
			th2[j]=th2[j-1]*base+(t2[j]-'a'+1);
			if(!l&&t1[j]!=t2[j])l=j;
			if(t1[j]!=t2[j])r=j;
		}
		ans=0;
		for(int j=1;j<=n;j++){//µÚj¸ös 
			if(len[j]<r-l+1)continue;
			for(int k=max(1,r-len[j]+1);k<=l&&k+len[j]-1<=siz;k++){
				if(h1[j]==get_h(th1,k,k+len[j]-1)&&h2[j]==get_h(th2,k,k+len[j]-1)){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
AFO
qwq
*/
