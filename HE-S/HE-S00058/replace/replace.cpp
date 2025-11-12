#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,V=5e6+5;
int n,q,sum1,sum2;
string s[N][2],t[N][2];
int ck(int y,int x){
	int len=s[x][0].size(),blen=t[y][0].size(),ans=0;
	for(int i=0;i+len-1<blen;i++){
		if(t[y][0].substr(i,len)==s[x][0]&&t[y][1].substr(i,len)==s[x][1]){
			string a0=t[y][0].substr(0,i),a1=t[y][1].substr(0,i);
			string b0=t[y][0].substr(i+len,blen-i-len),b1=t[y][1].substr(i+len,blen-i-len);
			if(a0==a1&&b0==b1) ans++;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		sum1+=s[i][0].size();sum1+=s[i][1].size();
	}
	for(int i=1;i<=q;i++){ 
		cin>>t[i][0]>>t[i][1];
		sum2+=t[i][0].size();sum2+=t[i][1].size();
	}
	if(n<=100&&q<=100&&sum1<=200&&sum2<=200){
		for(int i=1;i<=q;i++){
			int ans=0;
			int len0=t[i][0].size(),len1=t[i][1].size();
			if(len0!=len1){cout<<"0\n";continue;}
			for(int j=1;j<=n;j++) ans+=ck(i,j);
			cout<<ans<<'\n';
		}
		return 0;
	}else{
		for(int i=1;i<=q;i++){
			int len0=t[i][0].size(),len1=t[i][1].size();
			if(len0!=len1){cout<<"0\n";continue;}
			int l=len0-1,r=0;
			for(int j=0;j<len0;j++) if(t[i][0][j]!=t[i][1][j]) l=min(l,j),r=max(r,j);
			string tt0=t[i][0].substr(l,r-l+1),tt1=t[i][1].substr(l,r-l+1);
			int ans=0;
			for(int j=1;j<=n;j++)
				if(s[j][0].find(tt0)!=-1&&s[j][1].find(tt1)==s[j][0].find(tt0))
					ans+=(t[i][0].find(s[j][0])!=-1&&t[i][1].find(s[j][1])!=-1);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
