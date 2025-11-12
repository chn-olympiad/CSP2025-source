#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200005,M=5000000,mod=998244353;
const ll inf=0x3f3f3f3f;
#define pb push_back

int n,q; 
int p[M],base=13331;
vector<char> s[N][3];
vector<int> sm[N][3];
vector<char> t[N][3];
vector<int> ts[N][3];
char s1[M],s2[M];
int ans[N];
int sum1(int id,int bl,int l,int r){
	if(!l)return sm[id][bl][r];
	return (sm[id][bl][r]+mod-1ll*sm[id][bl][l-1]*p[r-l+1]%mod)%mod;
}
int sum2(int id,int bl,int l,int r){
	if(!l)return ts[id][bl][r];
	return (ts[id][bl][r]+mod-1ll*ts[id][bl][l-1]*p[r-l+1]%mod)%mod;
}
struct Sub1{
	void solve(){
		for(int i=1;i<=q;i++){
			if(t[i][1].size()!=t[i][2].size()){
				ans[i]=0;
				continue;
			}
			int l=0,r=0;
			for(int j=0;j<t[i][1].size();j++){
				if(t[i][1][j]!=t[i][2][j]){
					l=j;
					break;
				}
			}
			for(int j=t[i][1].size()-1;j>=0;j--){
				if(t[i][1][j]!=t[i][2][j]){
					r=j;
					break;
				}
			}
			int len=r-l+1,ss1=sum2(i,1,l,r),ss2=sum2(i,2,l,r);
			for(int j=1;j<=n;j++){
				for(int k=0;k+len-1<s[j][1].size();k++){
					int o=k+len-1;
					if(ss1==sum1(j,1,k,o)&&ss2==sum1(j,2,k,o)){
						int len1=k,len2=s[j][1].size()-1-o;
						if(len1<=l&&len2<=t[i][1].size()-1-r){
							int S1=sum2(i,1,l-len1,r+len2),S2=sum2(i,2,l-len1,r+len2);
							if(S1==sum1(j,1,0,s[j][1].size()-1)&&S2==sum1(j,2,0,s[j][1].size()-1))ans[i]++;
						}
					}
				}
			}
		}
		for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	}
}sub1;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr); 

	cin>>n>>q;
	
	int L1=0,L2=0,mx=0;	
	for(int i=1;i<=n;i++){
		cin>>(s1+1)>>(s2+1);
		int len=strlen(s1+1);
		for(int j=1;j<=len;j++)s[i][1].pb(s1[j]);
		for(int j=1;j<=len;j++)s[i][2].pb(s2[j]);
		L1+=2*len;
		mx=max(mx,len);
	}	
	
	for(int i=1;i<=q;i++){
		cin>>(s1+1)>>(s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		for(int j=1;j<=len1;j++)t[i][1].pb(s1[j]);
		for(int j=1;j<=len2;j++)t[i][2].pb(s2[j]);
		L2+=len1+len2;
		mx=max(mx,max(len1,len2));
	}
	p[0]=1;
	for(int i=1;i<=mx;i++)p[i]=1ll*p[i-1]*base%mod;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=0;j<s[i][1].size();j++)sum=(1ll*sum*base%mod+s[i][1][j]-'a')%mod,sm[i][1].pb(sum);
		sum=0;
		for(int j=0;j<s[i][1].size();j++)sum=(1ll*sum*base%mod+s[i][2][j]-'a')%mod,sm[i][2].pb(sum);
	}	
	
	for(int i=1;i<=q;i++){
		int sum=0;
		for(int j=0;j<t[i][1].size();j++){
			sum=(1ll*sum*base%mod+t[i][1][j]-'a')%mod;
			ts[i][1].pb(sum);
		}
		sum=0;
		for(int j=0;j<t[i][2].size();j++)sum=(1ll*sum*base%mod+t[i][2][j]-'a')%mod,ts[i][2].pb(sum);
	}
	sub1.solve(); 
	return 0;
} 
