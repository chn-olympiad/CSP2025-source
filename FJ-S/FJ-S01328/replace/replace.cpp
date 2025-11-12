#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,len1,len2,len,ans,ll;
string s[N][3],t1,t2;
vector<int> wy[10000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2],ll=ll+s[i][1].size()+s[i][2].size();
	if(ll>2000&&n>=1e3){
		int lx,ly;
		for(int i=1;i<=n;i++){
			len=s[i][1].size();
			for(int j=0;j<len;j++){
				if(s[i][1][j]=='b'){
					lx=j;
					break;
				}
			}
			for(int j=0;j<len;j++){
				if(s[i][2][j]=='b'){
					ly=j;
					break;
				}
			}
			wy[ll+lx-ly].push_back(lx);
		}
		for(int i=1;i<=ll*2;i++){
			if(wy[i].size()) sort(wy[i].begin(),wy[i].end());
		}
		while(q--){
			cin>>t1>>t2;
			len1=t1.size(),len2=t2.size();
			for(int i=0;i<len1;i++){
				if(t1[i]=='b'){
					lx=i;
					break;
				}
			}
			for(int i=0;i<len2;i++){
				if(t2[i]=='b'){
					ly=i;
					break;
				}
			}
			cout<<(lower_bound(wy[ll+lx-ly].begin(),wy[ll+lx-ly].end(),lx)-wy[ll+lx-ly].begin())<<"\n";
		}
		return 0;
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		len1=t1.size(),t1=' '+t1;
		len2=t2.size(),t2=' '+t2;
		if(len1!=len2){
			cout<<0<<"\n";
			continue;
		}
		bool pp;
		int ll,rr;
		for(int i=1;i<=n;i++){
			len=s[i][1].size();
			if(len1<s[i][1].size()) continue;
			for(int j=1;j<=len1;j++){
				pp=1;
				for(int k=0;k<len;k++){
					if(s[i][1][k]!=t1[j+k]){
						pp=0;
						break;
					}
				}
				if(!pp) continue;
				for(int k=0;k<j;k++){
					if(t1[k]!=t2[k]){
						pp=0;
						break;
					}
				}
				if(!pp) continue;
				for(int k=0;k<=len1-len-j;k++){
					if(t1[len1-k]!=t2[len2-k]){
						pp=0;
						break;
					}
				}
				if(!pp) continue;
				ll=j,rr=len+j-1;
				if(len2<s[i][2].size()) continue;
				for(int k=0;k<=rr-ll;k++){
					if(t2[k+ll]!=s[i][2][k]){
						pp=0;
						break;
					}
				}
				if(pp) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
