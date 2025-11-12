#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,len[200004],h[200005],l[200005],r[200055],hh[200005],b=29,bb=133,mod1=1e9+7,mod2=998244353,s[200005],ss[200005],po[200005],poo[200005];
string st[200005][2],t[3];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	po[0]=poo[0]=1;
	for(int i=1;i<=200000;i++)po[i]=po[i-1]*b%mod1;
	for(int i=1;i<=200000;i++)poo[i]=poo[i-1]*bb%mod2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>st[i][0]>>st[i][1];
		len[i]=st[i][0].size();
		l[i]=-1;
		for(int j=0;j<len[i];j++){
			h[i]=(h[i]*b+(st[i][0][j]-'a'))%mod1;
			hh[i]=(hh[i]*bb+(st[i][1][j]-'a'))%mod2;
		}
		for(int j=0;j<len[i];j++){
			if(st[i][0][j]==st[i][1][j]){
				l[i]=j;
			}else break;
		}
		r[i]=len[i];
		for(int j=len[i]-1;j>=0;j--){
			if(st[i][0][j]==st[i][1][j]){
				r[i]=j;
			}else break;
		}
	}
	while(q--){
		cin>>t[1]>>t[2];
		int ll=-1,rr=t[1].size(),le=t[1].size();
		for(int j=0;j<le;j++){
			s[j+1]=(s[j]*b+t[1][j]-'a')%mod1;
			ss[j+1]=(ss[j]*bb+t[2][j]-'a')%mod2;
		}
		for(int j=0;j<le;j++){	
			if(t[1][j]==t[2][j]){
				ll=j;
			}
			else break;
		}for(int j=le-1;j>=0;j--){
			if(t[1][j]==t[2][j]){
				rr=j;
			}else break;
		}
		int ans=0;
	//	cout<<ll<<"  "<<rr<<"\n";
		for(int i=1;i<=n;i++){
	//		cout<<l[i]<<" "<<r[i]<<"\n";
			if(rr-ll==r[i]-l[i]){
				int pl=ll-l[i],pr=pl+len[i]-1;
	//			cout<<pl<<" "<<pr<<"\n";
				if(h[i]==((s[pr+1]-s[pl]*po[len[i]]%mod1)+mod1)%mod1&&hh[i]==((ss[pr+1]-ss[pl]*poo[len[i]]%mod2)+mod2)%mod2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
