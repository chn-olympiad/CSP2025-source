#include<bits/stdc++.h>
using namespace std;
int n,q,ans,f[200005];
string sa[200005],sb[200005],qa,qb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>sa[i]>>sb[i];
	while(q--){
		ans=0;
		cin>>qa>>qb;
		int far=qa.size();
		string s,c;
		for(int i=0;i<far;i++){
			if(qa[i]!=qb[i]){
				s+=qa[i];
				c+=qb[i];
				if(f[i]) break;
			}else{
				if(s.size()!=0) f[i]=1;
			}
		}
		//N^3  <=30pts
		for(int i=1;i<=n;i++){
			if(sa[i].size()>=s.size() && sb[i].size()>=c.size()){
				for(int j=0;j<=sa[i].size();j++){
					if(sa[i][j]==s[0] && sb[i][j]==c[0]){
						string u,v;
						for(int o=j;o<j+s.size();o++) u+=sa[i][o];
						for(int o=j;o<j+c.size();o++) v+=sb[i][o];
						if(u==s && v==c) ans++;
					}
				}
			}	
		}
		//N?
		cout<<ans<<"\n";
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
skte
aercut
*/
