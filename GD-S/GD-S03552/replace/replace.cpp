#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=2e5+5,mod=998244353,inf=0x3f3f3f3f;
int n,q;
string s[MAXN][3];
vector<int> kmp[MAXN][3];
string t1,t2;
bool ss[MAXN],hh[MAXN];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		int len=s[i][1].size();
		s[i][1]='\0'+s[i][1];
		kmp[i][1].resize(len+1);
		for(int k=2,j;k<=len;k++){
			j=kmp[i][1][k-1];
			while(j&&s[i][1][j+1]!=s[i][1][k])
				j=kmp[i][1][j];
			if(s[i][1][j+1]==s[i][1][k])
				kmp[i][1][k]=kmp[i][1][j]+1;
		}
		s[i][2]='\0'+s[i][2];
		kmp[i][2].resize(len+1);
		for(int k=2,j;k<=len;k++){
			j=kmp[i][2][k-1];
			while(j&&s[i][2][j+1]!=s[i][2][k])
				j=kmp[i][2][j];
			if(s[i][2][j+1]==s[i][2][k])
				kmp[i][2][k]=kmp[i][2][j]+1;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int len=t1.size();
		t1='\0'+t1,t2='\0'+t2;
		ss[0]=hh[len+1]=1;
		for(int i=1;i<=len;i++){
			if(t1[i]!=t2[i]){
				while(i<=len)
					ss[i++]=0;
				break;
			}
			ss[i]=1;
		}
		for(int i=len;i>=1;i--){
			if(t1[i]!=t2[i]){
				while(i>=1)
					hh[i--]=0;
				break;
			}
			hh[i]=1;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int k=1,p1=0,p2=0;k<=len;k++){
				while(p1&&s[j][1][p1+1]!=t1[k])
					p1=kmp[j][1][p1];
				while(p2&&s[j][2][p2+1]!=t2[k])
					p2=kmp[j][2][p2];
				if(s[j][1][p1+1]==t1[k])
					++p1;
				if(s[j][2][p2+1]==t2[k])
					++p2;
				if(p1==s[j][1].size()-1&&p1==p2){
					if(ss[k-p1]&&hh[k+1])
						++ans;
					else
						break;
					p1=kmp[j][1][p1];
					p2=kmp[j][2][p2];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

