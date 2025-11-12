#include<bits/stdc++.h>
#define ll long long
#define N 200010
#define M 2000100
using namespace std;
ll n,m,ans;
ll f[N],g[N];
ll g1[N],g2[N];
ll a[N],b[N];
string s[N][3],t[N][3];
ll lon[N];
vector<ll>v[M];
void cn(){
	for(ll i=1;i<=m;i++)cout<<"0\n";
}
void kmp(string s1,string s2){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	ll i,j;
	ll l1=s1.size(),l2=s2.size();
	for(i=1,j=0;i<l2;i++){
		while(j&&s2[j]!=s2[i])j=g[j-1];
		if(s2[i]==s2[j])j++;
		g[i]=j;
//		cout<<g[i]<<" ";
	}
//	cout<<"\n";
	for(i=0,j=0;i<l1;i++){
		while(j&&s1[i]!=s2[j])j=g[j-1];
		if(s1[i]==s2[j])j++;
		f[i]=j;
		if(j==l2)j=g[j];
//		cout<<f[i]<<" ";
	}
//	cout<<"\n";
//	cout<<"\n";
}
bool pan(string s1,string s2,ll l,ll r){
	ll i,l1=s1.size();
//	cout<<s1<<" "<<s2<<" ";
//	cout<<l<<" "<<r<<" "<<l1<<"\n";
	if(l>=0){
		for(i=0;i<=l;i++)if(s1[i]!=s2[i])return 0;
	}
	if(r<l1){
		for(i=r;i<l1;i++)if(s1[i]!=s2[i])return 0;
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll i,j,k,x=0,y=0,z,lo;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		lon[i]=s[i][1].size();
		x+=lon[i]*2;
	}
	for(i=1;i<=m;i++){
		cin>>t[i][1]>>t[i][2];
		y+=t[i][1].size()*2;
	}
	if(x<=2000&&y<=2000){
		for(i=1;i<=m;i++){
			ans=0;
			for(j=1;j<=n;j++){
				kmp(t[i][1],s[j][1]);
				memcpy(g1,f,sizeof(g1));
				kmp(t[i][2],s[j][2]);
				memcpy(g2,f,sizeof(g2));
				for(k=0;k<t[i][1].size();k++){
//					cout<<g1[k]<<" "<<g2[k]<<"\n";
//						cout<<"1145141919180";
					if(g1[k]==g2[k]&&g1[k]==lon[j]){
						ans+=pan(t[i][1],t[i][2],k-lon[j],k+1);
					}
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=0;j<lon[i];j++){
			if(s[i][1][j]>'b'){
				cn();
				return 0;
			}
			if(s[i][1][j]=='b')a[i]=j;
			if(s[i][2][j]=='b')b[i]=j;
		}
		v[abs(a[i]-b[i])].push_back(i);
	}
	for(i=1;i<=m;i++){
		ans=0;
		lo=t[i][1].size();
		for(j=0;j<lo;j++){
			if(t[i][1][j]=='b')x=j;
			if(t[i][2][j]=='b')y=j;
		}
		z=abs(x-y);
		for(j=0;j<v[z].size();j++){
			k=v[z][j];
			if(x-y==a[k]-b[k]&&x>=a[k]&&lo-y>=lon[k]-b[k])ans++;
		}
		cout<<ans<<"\n";
	}
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
