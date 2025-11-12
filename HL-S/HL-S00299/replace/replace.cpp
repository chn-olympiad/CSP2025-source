#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5; 
int n,q;
map<string,string>mp;
string s1,s2;
int sum[N];
int check(int l,int r){
	return sum[r]-sum[l-1];
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--){
		int ans=0;
		memset(sum,0,sizeof sum);
		cin>>s1>>s2;
		int length=s1.length(),need=0;
		for(int i=0;i<length;i++){
			if(s1[i]!=s2[i]) sum[i]=sum[i-1]+1,need++;
			else sum[i]=sum[i-1];
		} 
		for(int len=1;len<=length;len++){
			for(int l=0;l+len-1<length;l++){
				int r=l+len-1;
				string tmp1=s1.substr(l,len),tmp2=s2.substr(l,len);
				if(mp[tmp1]==tmp2&&check(l,r)>=need){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
