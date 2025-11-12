#include <bits/stdc++.h>
#define l first
#define r second
using namespace std;
int sum,n,q,l,r;
pair<int,int> dif[200005];
string s[200005],t[200005],ss,tt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		dif[i].l=2e9;
		for(int j=0;j<(int)s[i].size();j++) if(s[j]!=t[j]){
			dif[i].l=min(dif[i].l,j);
			dif[i].r=j;
		}
	} 
	while(q--){
		cin>>ss>>tt;
		l=2e9;
		sum=r=0;
		if((int)ss.size()!=(int)tt.size()){
			cout<<"0\n";
			continue;
		} 
		for(int i=0;i<(int)ss.size();i++) if(ss[i]!=tt[i]){
			l=min(l,i);
			r=i;
		}
		string tmps=ss.substr(l,r-l+1),tmpt=tt.substr(l,r-l+1);
		for(int i=1;i<=n;i++) if(dif[i].r-dif[i].l+1<=(int)tmps.size()&&(int)s[i].size()<=(int)ss.size()){
			int pos=s[i].find(tmps,0),poss=t[i].find(tmpt,0);
			if(!(~pos)||!(~poss)||pos!=poss) continue;
			bool fl=0;
			int j=pos,jj=l;
			if((int)s[i].size()-j>(int)ss.size()-jj) continue;
			for(;j<(int)s[i].size();j++,jj++) if(s[i][j]!=ss[jj]||t[i][j]!=tt[jj]){
				fl=1;
				break;
			}
			sum+=!fl;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
