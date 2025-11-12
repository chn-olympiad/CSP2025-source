#include <bits/stdc++.h>
#define ll long long
#define rep(t,l,r) for(int t=l;t<=r;t++)
#define per(t,l,r) for(int t=r;t>=l;t--)

using namespace std;
const int N=2e5+10,M=5e6+10;
int n,q,len1[N],len2[N];
string s1[N],s2[N],q1[N],q2[N];

signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int cnt1=0,cnt2=0;
	cin>>n>>q; rep(i,1,n) {
		cin>>s1[i]>>s2[i];
		len1[i]=s1[i].size(); 
		cnt1+=s1[i].size()+s2[i].size();
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
	}
	rep(i,1,q) {
		cin>>q1[i]>>q2[i]; 
		len2[i]=q1[i].size();
		cnt2+=q1[i].size()+q2[i].size(); 
		q1[i]=" "+q1[i];
		q2[i]=" "+q2[i];
	}
	if(n<=1000&&cnt1<=2000&&cnt2<=2000) {
		rep(i,1,q) {
			int ans=0;
			rep(j,1,n) {
				bool flg=false;
				rep(pos,1,len2[i]-len1[j]+1) {
					bool ok=true;
					rep(t,pos,pos+len1[j]-1) {
//						if(i==2) cerr<<q1[i][t]<<" "<<s1[j][t-pos+1]<<endl;
						ok&=(q1[i][t]==s1[j][t-pos+1]);
					}
					if(ok==false) continue;
					string tmp="";
					rep(t,1,pos-1) tmp+=q1[i][t];
					rep(t,pos,pos+len1[j]-1) tmp+=s2[j][t-pos+1];
					rep(t,pos+len1[j],len2[i]) tmp+=q1[i][t];
					tmp=" "+tmp;
					if(tmp==q2[i]) {flg=true; break;}
				}
				if(flg==true) ans++;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	return 0;
}
