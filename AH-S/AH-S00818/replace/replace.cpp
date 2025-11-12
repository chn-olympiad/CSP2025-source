#include<bits/stdc++.h>
using namespace std;
const long long Mod1=1095549601,Mod2=1078765967,N=5e6+5;
bool st;
string s1[200005],s2[200005];
void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		string p1,p2;
		cin>>p1>>p2;
		p1=" "+p1;
		p2=" "+p2;
		int l1=p1.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			int len=s1[i].size(),QwQ=s2[i].size();
			for(int st=1;st+min(len,QwQ)-1<l1;st++){
				int ed=st+len-1;
				if(s1[i]==p1.substr(st,len)){
					string temp=" "+p1.substr(1,st-1)+s2[i]+p1.substr(ed+1,l1-ed);
					if(temp==p2)
						ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--)
		solve();
	return 0;
}