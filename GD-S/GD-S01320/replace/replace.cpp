#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,P=131;
int n,q,a[200010][2],f[5000010],f1[5000010],pw[5000010],cd[5000010];
string s,t,t1;
int check(int l,int r){
	if(l>r)return 1;
	int w=(f[r]-(l>0?f[l-1]*pw[r-l+1]%mod:0)+mod)%mod;
	int w1=(f1[r]-(l>0?f1[l-1]*pw[r-l+1]%mod:0)+mod)%mod;
	if(w==w1)return 1;
	return 0;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	pw[0]=1;
	for(int i=1;i<=5000000;i++){
		pw[i]=pw[i-1]*P%mod;
	}
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s;
		cd[i]=s.size();
		int w=0;
		for(int j=0;j<s.size();j++){
			w=(w*P+(s[j]-'a'+1))%mod;
		}
		a[i][0]=w;
		cin>>s;
		w=0;
		for(int j=0;j<s.size();j++){
			w=(w*P+(s[j]-'a'+1))%mod;
		}
		a[i][1]=w;
	}
	while(q--){
		cin>>t;
		cin>>t1;
		if(t.size()!=t1.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<t.size();i++){
			if(i>0){
				f[i]=(f[i-1]*P+t[i]-'a'+1)%mod;
				f1[i]=(f1[i-1]*P+t1[i]-'a'+1)%mod;
			}
			else{
				f[i]=t[i]-'a'+1;
				f1[i]=t1[i]-'a'+1;
			}
			//cout<<f[i]<<" "<<f1[i]<<endl;
		}
		int ans=0;
		for(int i=0;i<t.size();i++){
			if(!check(0,i-1))break;
			for(int j=t.size()-1;j>=i;j--){
				
				if(!check(j+1,t.size()-1))break;
			//	cout<<i<<" "<<j<<endl;
				for(int k=1;k<=n;k++){
					if(j-i+1!=cd[k])continue;
					int w=(f[j]-(i>0?f[i-1]*pw[j-i+1]%mod:0)+mod)%mod;
					int w1=(f1[j]-(i>0?f1[i-1]*pw[j-i+1]%mod:0)+mod)%mod;
					if(w==a[k][0]&&w1==a[k][1]){
					//	cout<<w<<" "<<w1<<" "<<k<<endl;
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
