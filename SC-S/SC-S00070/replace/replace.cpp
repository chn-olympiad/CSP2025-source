#include<bits/stdc++.h>
using namespace std;
long long n,q;
string ls[5001],rs[5001];
string lt[5001],rt[5001];
string qc(string now,int l,int r){
	string rt;
	if(r<l){
		return rt;
	}
	for(int i=l-1;i<r;i++){
		rt+=now[i];
	}
	return rt;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ls[i]>>rs[i];
	}
	long long ans;
	for(int i=1;i<=q;i++){
		cin>>lt[i]>>rt[i];
		ans=0;
		for(int l=1;l<=rt[i].size();l++){
			for(int j=1;j<=n;j++){
				if(l+rs[j].size()>rt[i].size()+1){
					continue;
				}
				string lw=qc(rt[i],l,l+rs[j].size()-1);
				if(lw!=rs[j]){
					continue;
				}
				if(qc(rt[i],1,l-1)+ls[j]+qc(rt[i],l+rs[j].size(),rt[i].size())==lt[i]){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}