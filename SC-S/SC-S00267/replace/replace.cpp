#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10,MAXM=5e6+10;
string s[MAXN][2],S[2];
long long n,m,ans,mxlen,LEN,len[MAXN],hsh[MAXN][2],sum[MAXN],HSH[MAXM][2],s131[MAXM],L,R;
map<pair<long long,long long>,long long>mp,mp2,mp3;
long long cha0(long long l,long long r){
	return HSH[r][0]-HSH[l-1][0]*s131[r-l+1];
}
long long cha1(long long l,long long r){
	return HSH[r][1]-HSH[l-1][1]*s131[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		len[i]=s[i][0].length();
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<len[i];j++){
			hsh[j][0]=hsh[j][0]*131+s[j][0][len[j]];
			hsh[j][1]=hsh[j][1]*131+s[j][1][len[j]];
		}
	}
	for(int i=1;i<=m;i++){
		L=R=0;
		ans=0;
		cin>>S[0]>>S[1];
		LEN=S[0].length();
		s131[0]=1;
		for(int j=1;j<=LEN;j++){
			s131[j]=s131[j-1]*131;
			HSH[j][0]=HSH[j-1][0]*131+S[0][j-1];
			HSH[j][1]=HSH[j-1][1]*131+S[1][j-1];
			if(S[0][j-1]!=S[1][j-1]){
				if(!L){
					L=j;
				}else if(!R){
					R=j;
				}else{
					ans=-1;
					break;
				}
			}
		}
		if(ans==-1){
			cout<<"0\n";
			continue;
		}
		for(int j=1;j<=n;j++){
			for(int k=len[j];k<=LEN;k++){
				if(k-len[j]+1<=L&&k>=R){
					if(cha0(k-len[j]+1,k)==hsh[j][0]&&cha1(k-len[j]+1,k)==hsh[j][1])ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}