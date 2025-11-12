#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rnd(time(0));
inline int rd(int l,int r){return rnd()%(r-l+1)+l;}
const int MAXN=2e5+5,MAXM=2.5e6+5,M=2.5e6;
int n,q;
const int SIZ=10;
int zh[SIZ][26][26];
const int mod[SIZ]={1000000021,1000000033,1000000087,1000000093,1000000097,1000000103,1000000123,1000000181,1000000207,1000000223};
const int base[SIZ]={25293836,971644423,955474394,548607842,942324944,120881775,358193182,188734575,567522790,890167988};
inline int ksm(int a,int b,int mod){int cnt=1;while(b){if(b&1)cnt=(ll)cnt*a%mod;a=(ll)a*a%mod;b>>=1;}return cnt;}
int inv[SIZ][MAXM];
inline void init(){
	for(int j=0;j<SIZ;j++){
		int I=ksm(base[j],mod[j]-2,mod[j]);
		inv[j][0]=1;
		for(int i=1;i<=M;i++){
			inv[j][i]=(ll)inv[j][i-1]*I%mod[j];
		}
	}
}
int vl[SIZ];map<vector<int>,int>mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>q;init();
	for(int k=0;k<SIZ;k++){
		for(int i=0;i<=25;i++)for(int j=0;j<=25;j++){
			if(i==j)zh[k][i][j]=0;
			else zh[k][i][j]=rd(1,1e9);
		}
	}
	for(int i=1;i<=n;i++){
		string s[2];cin>>s[0]>>s[1];
		vector<int>now;
		for(int j=0;j<SIZ;j++){
			int del=0;
			for(int k=0;k<s[0].size();k++){
				del=((ll)del*base[j]+zh[j][s[0][k]-'a'][s[1][k]-'a'])%mod[j];
			}
			now.push_back(del);
		}
		mp[now]++;
	}
	while(q--){
		string T[2];cin>>T[0]>>T[1];
		if(T[0].size()!=T[1].size()){
			cout<<"0\n";continue;
		}
		for(int j=0;j<SIZ;j++){
			vl[j]=0;
			for(int i=0;i<T[0].size();i++){
				vl[j]=((ll)vl[j]*base[j]+zh[j][T[0][i]-'a'][T[1][i]-'a'])%mod[j];
			}
		}
		int sz=T[0].size(),res=0,flag=1;
		for(int i=(int)T[0].size()-1;i>=0;i--){
			vector<int>now;
			for(int j=0;j<SIZ;j++){
				now.push_back((ll)vl[j]*inv[j][sz-i-1]%mod[j]);
			}
			if(mp.find(now)!=mp.end())res+=mp[now];
		}
		cout<<res<<"\n";
	}
}