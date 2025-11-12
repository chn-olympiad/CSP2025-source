#include<bits/stdc++.h>

using namespace std;
const int N=2e5+10,M=N<<1,inf=0x3f3f3f3f;

inline int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48; c=getchar();}
	return x*f;
}
int n,q,ans;
string s[N][2],t[N][2];
void solve(){
	n=read(),q=read();
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t[i][0]>>t[i][1];
		if(t[i][0].size()!=t[i][1].size()){
			puts("0");
			continue; 
		}
		int len=t[i][0].size();
		int L,R,j=0;
		while(t[i][0][j]==t[i][1][j]&&j<=len) j++;
		L=j,R=j;
		for(;j<len;j++) if(t[i][0][j]!=t[i][1][j]) R=j;
		for(j=1;j<=n;j++){
			int l=s[j][0].size();
			for(int k=0;k<len;k++){
				int kk=k,cnt=0;
				while(t[i][0][kk]==s[j][0][cnt]&&t[i][1][kk]==s[j][1][cnt]){
//					cout<<">>>"<<k<<">>>"<<t[i][0][kk]<<' '<<s[j][0][cnt]<<endl;
					cnt++,kk++;
					if(cnt==l){
						if(k<=L&&kk-1>=R) ans++;
						else break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}

}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;
}

