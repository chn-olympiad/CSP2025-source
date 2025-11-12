#include<bits/stdc++.h>
#define int long long
using namespace std;

pair<string,string> eyz[200010];
int mod=1e14+7,bs=26;

int hx(string x,int l,int r){
	if(l>r)return 0;
	int ans=0;
	for(int i=l;i<=r;i++){
		ans+=(x[i]-'a');
		ans%=mod;
		ans*=bs;
		ans%=mod;
	}
	return ans;
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//cout<<hx("dyx");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>eyz[i].first>>eyz[i].second;
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<'\n';
			continue;
		}
		for(int l=0;l<a.size();l++){
			for(int r=0;r<a.size();r++){
				for(int i=1;i<=n;i++){
					if(eyz[i].first.size()!=r-l+1)continue;
					if((hx(a,l,r)==hx(eyz[i].first,0,eyz[i].first.size()-1))&&(hx(b,l,r)==hx(eyz[i].second,0,eyz[i].second.size()-1))&&(hx(a,0,l-1)==hx(b,0,l-1))&&(hx(a,r+1,a.size()-1)==hx(b,r+1,a.size()-1))){
						//cout<<l<<' '<<r<<' '<<i<<endl;
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
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
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
