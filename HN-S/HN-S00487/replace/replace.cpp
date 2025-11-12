#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string v[200005][2];
int insh[200005][2];
string in1,in2;
int hash1[5000005];
int hash2[5000005];
int lot[5000005];
int base=2e6+3,mod=999900991;
int hash_1(int l,int r){
	if(l>r)return -1;
	return ((hash1[r]-hash1[l-1]*lot[r-l+1]%mod)%mod+mod)%mod;
}
int hash_2(int l,int r){
	if(l>r)return -1;
	return ((hash2[r]-hash2[l-1]*lot[r-l+1]%mod)%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>v[i][0]>>v[i][1];
		for(int j=0;j<v[i][0].size();j++){
			insh[i][0]=(insh[i][0]*base%mod+v[i][0][j])%mod;
			insh[i][1]=(insh[i][1]*base%mod+v[i][1][j])%mod;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>in1>>in2;
		int len=in1.size();
		in1='0'+in1;
		in2='0'+in2;
		lot[0]=1;
		for(int j=1;j<=len;j++){
			hash1[j]=(hash1[j-1]*base%mod+in1[j])%mod;
			hash2[j]=(hash2[j-1]*base%mod+in2[j])%mod;
			lot[j]=lot[j-1]*base%mod;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int l=1,r=v[j][0].size();r<=len;l++,r++){
				if(hash_1(1,l-1)==hash_2(1,l-1)
				&&hash_1(l,r)==insh[j][0]
				&&insh[j][1]==hash_2(l,r)
				&&hash_1(r+1,len)==hash_2(r+1,len)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

