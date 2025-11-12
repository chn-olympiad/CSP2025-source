#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],t[200005];
string p1,p2;
int id;
unordered_map<int,int>mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		cin>>p1>>p2;
		if(p1.size()!=p2.size()){
			cout<<0<<'\n';
			continue;
		}
		int sizp=p1.size();
		id=-1;
		int cnt=0;
		for(int i=0;i<sizp;i++){
			if(p1[i]!=p2[i]){
				if(id==-1)id=i;
				cnt++;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int siz=s[i].size();
			int ii=-1;
			int cnt2=0;
			for(int j=0;j<siz;j++){
				if(s[i][j]!=t[i][j]){
					if(ii==-1)
					ii=j;
					cnt2++;
				}
			}
			if(cnt!=cnt2){
				continue;
			}
			if(ii==-1)continue;
			if(id<ii)continue;
			bool flag=1;
			for(int j=0;j<siz;j++){
				if(j+id-ii>=sizp||s[i][j]!=p1[j+id-ii]||t[i][j]!=p2[j+id-ii]){
					flag=0;
					break;
				}
			}
			ans+=flag;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

