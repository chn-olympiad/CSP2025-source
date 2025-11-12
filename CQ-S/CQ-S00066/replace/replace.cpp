#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int H=131;
const int MAXN=500005;
const int MAXM=6000005;
int n,m;
int l[MAXN];
int r[MAXN];
ull h[MAXM];
//ull ls[MAXN][2];
//ull rs[MAXN][2];
//ull mid[MAXN][2];
ull all[MAXN][2];
ull sum[MAXM][2];
string s[MAXN][2];
int get_ha(int l,int r,int op){
	return sum[r][op]-sum[l-1][op]*h[r-l+1];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	h[0]=1;
	for(int i=1;i<=5000000;i++){
		h[i]=h[i-1]*H;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=m;i++){
		cin>>s[i+n][0]>>s[i+n][1];
	}
	for(int i=1;i<=n;i++){
		int len=s[i][0].length();
		for(int j=0;j<len;j++){
			if(s[i][0][j]!=s[i][1][j]){
				if(!l[i]){
					l[i]=j+1;
				}
				r[i]=j+1;
			}
		}
		if(!l[i]){
			l[i]=1;
			r[i]=len;
		}
		//cout<<"i="<<i<<" "<<l[i]<<" "<<r[i]<<endl;
		for(int j=0;j<len;j++){
			for(int k=0;k<=1;k++){
				all[i][k]=all[i][k]*H+(s[i][k][j]-'a'+1);
			}
		}
//		for(int j=l[i]-1;j<=r[i]-1;j++){
//			for(int k=0;k<=1;k++){
//				mid[i][k]=mid[i][k]*H+(s[i][k][j]-'a'+1);
//			}
//		}
////		for(int j=0;j<=1;j++){
////			ln[i][j]=l[i];
////			rn[i][j]=
////		}
//		for(int j=0;j<l[i]-1;j++){
//			for(int k=0;k<=1;k++){
//				ls[i][k]=ls[i][k]*H+(s[i][k][j]-'a'+1);
//			}
//		}
//		for(int j=r[i];j<len;j++){
//			for(int k=0;k<=1;k++){
//				rs[i][k]=rs[i][k]*H+(s[i][k][j]-'a'+1);
//			}
//		}
	}
	//cout<<"a"<<endl;
	for(int i=1;i<=m;i++){
		if(s[i+n][0].length()!=s[i+n][1].length()){
			cout<<"0"<<endl;
			continue;
		}
		int len=s[i+n][0].length();
		for(int j=0;j<len;j++){
			if(s[i+n][0][j]!=s[i+n][1][j]){
				if(!l[i+n]){
					l[i+n]=j+1;
				}
				r[i+n]=j+1;
			}
		}
		sum[0][0]=0;
		sum[0][1]=0;
		for(int j=1;j<=len;j++){
			for(int k=0;k<=1;k++){
				sum[j][k]=sum[j-1][k]*H+(s[i+n][k][j-1]-'a'+1);
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
//			if(r[i+n]-l[i+n]+1!=r[j]-l[j]+1||get_ha(l[i]-1,r[i]-1,1)!=mid[j][0]||get_ha(l[i]-1,r[i]-1,1)!=mid[j][1]){
//				continue;
//			}
			int ln=l[j];
			int rn=(s[j][0].length()-r[j]+1);
			//cout<<"i="<<i<<" "<<j<<" "<<l[i+n]<<" "<<r[i+n]<<" "<<l[i+n]-ln+1<<" "<<r[i+n]+rn-1<<" "<<get_ha(l[i+n]-ln+1,r[i+n]+rn-1,0)<<" "<<get_ha(l[i+n]-ln+1,r[i+n]+rn-1,1)<<" "<<all[j][0]<<" "<<all[j][1]<<endl;
			if(l[i+n]-ln+1<1||r[i+n]+rn-1>len){
				continue;
			}
			if(get_ha(l[i+n]-ln+1,r[i+n]+rn-1,0)==all[j][0]&&get_ha(l[i+n]-ln+1,r[i+n]+rn-1,1)==all[j][1]){
				ans++;
			}
//			if(get_ha(l[i]-ln+1,l[i],0)==ls[j][0]&&get_ha(l[i]-ln+1,l[i],1)==ls[j][1]&&get_ha(r[i],,0)==ls[j][0]){
//				ans++;
//			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
