#include<bits/stdc++.h>
using namespace std;
int n,q;
string ta,tt,tb,ts,sa[500006],sb[500006];
int pd(int l,int r){
	tt=ts="";
	for(int i=l;i<=r;i++) tt+=ta[i],ts+=tb[i];
	for(int i=1;i<=n;i++)
		if(tt==sa[i]&&sb[i]==ts) return 1;
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>sa[i]>>sb[i];
	if(n<=100){
		while(q--){
			int ans=0;
			cin>>ta>>tb;
			int l=ta.size(),r=0;
			for(int i=0;i<ta.size();i++)
				if(ta[i]!=tb[i]) l=min(l,i),r=max(r,i);
			for(int i=0;i<=l;i++)
				for(int j=r;j<ta.size();j++) ans+=pd(i,j);
			cout<<ans<<'\n';
		}
	}
	while(q--){
		int ans=0;
		int wa,wb;
		cin>>ta>>tb;
		for(int i=0;i<ta.size();i++){
			if(ta[i]=='b') wa=i;	
			if(tb[i]=='b') wb=i;
		}
		for(int i=1;i<=n;i++){
			int aw,bw,nn=sa[i].size();
			for(int j=0;j<sa[i].size();j++){
				if(sa[i][j]=='b') aw=j;	
				if(sb[i][j]=='b') bw=j;
			}
			if(aw<=wa&&ta.size()-wa>=nn-aw)
				if(wa-wb==aw-bw) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}