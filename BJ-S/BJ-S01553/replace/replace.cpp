#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int Mod = 998244353;
int a[N],cnt,n,Q,c[N],dp[N][N][N];
string s[N],t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>t[i];
	for(int func=1;func<=Q;func++){
		string S,T; cin>>S>>T;
		int len=S.size()-1; vector<int> p;
		for(int j=0;j<=len;j++)
			if(S[j]!=T[j]) p.push_back(j);
		int l=p.size();
		string s_,t_; s_="",t_="";
		s_=s_+S[p[0]],t_=t_+T[p[0]];
		for(int i=1;i<l;i++){
			if(p[i]!=p[i-1]+1)
				for(int j=p[i]+1;j<=p[i-1];j++)
					s_=s_+S[j],t_=t_+T[j];
			else
				s_=s_+S[p[i]],t_=t_+T[p[i]];
		
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			string ss=S;
			for(int j=0;j<=len;j++){
				if(j+s[i].size()-1<=len && S.substr(j,s[i].size())==s[i]){
					for(int k=j;k<=j+s[i].size()-1;k++){
						ss[k]=t[i][k-j];
					}
					break;
				}
				
			}
			ans+=(ss==T);
		}
		cout<<ans<<'\n';
	}
	return 0;
}