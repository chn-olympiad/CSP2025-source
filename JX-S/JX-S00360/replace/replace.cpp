//replace
#include<bits/stdc++.h>
using namespace std;
#define LOCAL
//#define int long long
#define emdl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=1e5+5;//!!

int n,q;
string s[MAXN][2+2];
string t[MAXN][2+2];

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef LOCAL
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t[i][1]>>t[i][2];
		
		int lent=t[i][1].size();
		for(int j=1;j<=n;j++){
			int lens=s[j][1].size();
			for(int l=0;l<=lent-lens+1;l++){
//				cout<<l<<emdl;//
				int r=l+lens;
				string x="";
				for(int ii=0;ii<l;ii++){
					x=x+t[ii][1];
				}
				string y="";
				for(int ii=l;ii<=r;ii++){
					y=y+t[ii][1];
				}
				string z="";
				for(int ii=r+1;ii<lent;ii++){
					z=z+t[ii][1];
				}
				
//				cout<<x<<"/"<<y<<"/"<<z<<"/"<<"----------";//
				
				string xx="";
				for(int ii=0;ii<l;ii++){
					xx=xx+t[ii][2];
				}
				string yy="";
				for(int ii=l;ii<=r;ii++){
					yy=yy+t[ii][2];
				}
				string zz="";
				for(int ii=r+1;ii<lent;ii++){
					zz=zz+t[ii][2];
				}
				
//				cout<<xx<<"/"<<yy<<"/"<<zz<<"/"<<emdl;//
				
				if(y==s[j][1] && yy==s[j][2]){
					if(x==xx && z==zz){
						ans++;
					}
				}
			}
		}
		cout<<ans<<emdl;
	}
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2
0
*/
