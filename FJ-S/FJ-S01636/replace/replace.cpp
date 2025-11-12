#include<bits/stdc++.h>
using namespace std;
#define int long long
#define piii pair<int,pair<int,int> >
#define fi first
#define se second
int mod1=13713;
int mod2=793;
int mod3=3171;
int n,q;
piii a[200005][2];
map<piii,piii> mp;
string x,y;
int ha(string s,int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){ans=(ans*71+s[i]-'a'+1)%mod1;}
	return ans;}
int hb(string s,int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){ans=(ans*37+s[i]-'a'+1)%mod2;}
	return ans;}
int hc(string s,int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){ans=(ans*31+s[i]-'a'+1)%mod3;}
	return ans;}
piii hh(string s,int l,int r){
	if(l>r)return {-1,{-1,-1}};
	return {ha(s,l,r),{hb(s,l,r),hc(s,l,r)}};
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i][0]=hh(x,0,x.length()-1);
		a[i][1]=hh(y,0,y.length()-1);
		mp[a[i][0]]=a[i][1];
	}
	while(q--){
		cin>>x>>y;
		int ans=0;
		int len=x.length();
		for(int i=0;i<len;i++){
			for(int j=i;j<len;j++){
//				cout<<i<<' '<<j<<":::";
//				cout<<mp[hh(x,i,j)].fi<<" ";
//				cout<<hh(y,i,j).fi<<endl;
				if(mp[hh(x,i,j)]==hh(y,i,j)&&
				hh(x,0,i-1)==hh(y,0,i-1)&&
				hh(x,j+1,len-1)==hh(y,j+1,len-1)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
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
