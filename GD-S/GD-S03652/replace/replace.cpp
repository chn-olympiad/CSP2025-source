#include<bits/stdc++.h>
#define int long long
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define rep1(i,s,t) for(int i=s;i<t;i++)
#define frep(i,s,t) for(int i=s;i>=t;i--)
#define frep1(i,s,t) for(int i=s;i>t;i++)
#define mset(ai,k) memset(ai,k,sizeof(ai))
using namespace std;
const int N=4e5+5,P=29,PP=97,mod=1e6+7;
int n,q,ans=0,l,hs,hi[N],ai[N],bi[N],ci[N],st,en,sm1=0,f[N],ff[30];
bool iss=1;
map<int,int>mi;
string s[N][2],t[N][2];
int md(int x){return (x%mod);}
int gt(char a,char b){
	return (a-'a')*P+(b-'a');
}
vector<int>vi[N];
bool is;
bool chk(string a){
	rep(i,0,26)ff[i]=0;
	rep1(i,0,a.size()){
		if(a[i]>='b')return 0;
		ff[a[i]-'a']++;
	}
	return (ff[1]==1);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	rep(i,1,n){
		cin>>s[i][0]>>s[i][1];
		iss&=chk(s[i][0]);iss&=chk(s[i][1]);
		l=hs=0;
		while(l<=s[i][0].size()-1&&s[i][0][l]==s[i][1][l])l++;
		st=l;
		l=s[i][0].size()-1;
		while(l>=0&&s[i][0][l]==s[i][1][l])l--;
		en=l;
		ai[i]=st;bi[i]=en;
	//	cout<<ai[i]<<' '<<bi[i]<<endl;
	}
	rep(i,1,q){
		cin>>t[i][0]>>t[i][1];
		iss&=chk(t[i][0]);iss&=chk(t[i][1]);
	}
//	if(iss){
//		rep(i,1,n){
//			if(bi[i]<0){
//				rep1(j,0,s[i][0].size())if(s[i][j]=='b')ai[i]=j,bi[i]=s[i][0].size()-j;
//				f[0].
//			}
//		}
//		return 0;
//	}
	rep(i,1,q){
		l=hs=ans=0;
		while(l<=t[i][0].size()-1&&t[i][0][l]==t[i][1][l])l++;
		st=l;
		l=t[i][0].size()-1;
		while(l>=0&&t[i][0][l]==t[i][1][l])l--;
		en=l;
	//	cout<<st<<" "<<en<<endl;
		if(st<=en){
			rep(j,1,n)if(bi[j]-ai[j]==en-st){
				is=1;
				rep(k,0,en-st){
					if(gt(s[j][0][ai[j]+k],s[j][1][ai[j]+k])!=gt(t[i][0][st+k],t[i][1][st+k])){is=0;break;}
				}//cout<<j<<" "<<is<<endl;
				if(!is)continue;
				rep(k,1,ai[j])if(gt(s[j][0][ai[j]-k],s[j][1][ai[j]-k])!=gt(t[i][0][st-k],t[i][1][st-k])){
					is=0;break;
				}//cout<<j<<" "<<is<<endl;
				if(!is)continue;
				rep(k,1,s[j][0].size()-bi[j]-1)if(gt(s[j][0][bi[j]+k],s[j][1][bi[j]+k])!=gt(t[i][0][en+k],t[i][1][en+k])){
					is=0;break;
				}//cout<<j<<" "<<is<<endl;
				if(!is)continue;
				ans++;
			}
		}
		else{
			rep(j,1,n){
				rep(p,0,t[i][0].size()-s[j][0].size()){
					is=1;
					rep(o,0,s[j][0].size()-1)if(gt(s[j][0][o],s[j][1][o])!=gt(t[i][0][o+p],t[i][1][o+p])){
						is=0;break;
					}
					ans+=is;
				}
			}
		}
		cout<<ans<<endl;
	}
}
