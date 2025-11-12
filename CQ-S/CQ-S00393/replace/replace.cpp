#include<bits/stdc++.h>
using namespace std;
#define int long long
const int bas1=1e4+7,bas2=1013;
const int mod1=1e9+7,mod2=998244353;
#define pa pair<int,int>
#define mkp make_pair
#define FI first
#define SE second
int n,q,num[2][2],ed[200005][2][2],bas[5000005][2];
int qz[5000005][2][2],len[5000005];
pa dif[5000005];
map<pa,int> mp;
string s1,s2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	bas[0][0]=bas[0][1]=1;
	for(int i=1;i<=5000000;i++){
		bas[i][0]=bas[i-1][0]*bas1%mod1;
		bas[i][1]=bas[i-1][1]*bas2%mod2;
	}
	for(int i=1,x;i<=n;i++){
		cin>>s1>>s2;
		x=s1.length();
		len[i]=x;
		num[0][0]=num[0][1]=num[1][0]=num[1][1]=0;
		for(int j=0;j<x;j++){
			num[0][0]=(num[0][0]+bas[x-j-1][0]*(s1[j]-'a'+1))%mod1;
			num[0][1]=(num[0][1]+bas[x-j-1][1]*(s1[j]-'a'+1))%mod2; 
			num[1][0]=(num[1][0]+bas[x-j-1][0]*(s2[j]-'a'+1))%mod1;
			num[1][1]=(num[1][1]+bas[x-j-1][1]*(s2[j]-'a'+1))%mod2; 
		}
		ed[i][0][0]=num[0][0];
		ed[i][0][1]=num[0][1];
		ed[i][1][0]=num[1][0];
		ed[i][1][1]=num[1][1];	
//		cout<<num[0][0]<<"\n";
		dif[i]=mkp((ed[i][1][0]-ed[i][0][0]+mod1)%mod1,(ed[i][1][1]-ed[i][0][1]+mod2)%mod2);	
	}
	for(int i=1,x,y,z,ans;i<=q;i++){
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<"0\n";
			continue;
		}
		ans=0;
		x=s1.length();
		s1=' '+s1;
		s2=' '+s2;
		qz[0][0][0]=qz[0][0][1]=qz[0][1][0]=qz[0][1][1]=0;
		for(int j=1;j<=x;j++){
			qz[j][0][0]=(qz[j-1][0][0]+bas[x-j][0]*(s1[j]-'a'+1))%mod1;
			qz[j][0][1]=(qz[j-1][0][1]+bas[x-j][1]*(s1[j]-'a'+1))%mod2; 
			qz[j][1][0]=(qz[j-1][1][0]+bas[x-j][0]*(s2[j]-'a'+1))%mod1;
			qz[j][1][1]=(qz[j-1][1][1]+bas[x-j][1]*(s2[j]-'a'+1))%mod2;
		}
		pa gg=mkp((qz[x][1][0]-qz[x][0][0]+mod1)%mod1,(qz[x][1][1]-qz[x][0][1]+mod2)%mod2);
		mp.clear();
//		cout<<qz[x][0][0]<<'\n';
		for(int j=1;j<=n;j++){
			for(int k=x;k>=0;k--){
				if(k+len[j]<=x){
					y=(qz[k][0][0]+ed[j][0][0]*bas[x-k-len[j]][0]%mod1)%mod1;
					z=(qz[k][0][1]+ed[j][0][1]*bas[x-k-len[j]][1]%mod2)%mod2;
//					if(i==1&&j==1&&k==0)cout<<y<<' '<<z<<"\n";
					if(mp[mkp(y,z)]){
//						cout<<"11"<<' '<<i<<' '<<j<<' '<<k<<'\n';
						if(gg==mkp(dif[j].FI*bas[x-k-len[j]][0],dif[j].SE*bas[x-k-len[j]][1])){
							ans++;
							break;
						}
					}	
				}
				
				mp[mkp(qz[k][0][0],qz[k][0][1])]++;
//				if(i==1&&j==2)cout<<qz[k][0][0]<<' '<<qz[k][0][1]<<"\n";
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
abc ade
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

