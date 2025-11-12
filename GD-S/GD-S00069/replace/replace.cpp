#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;
string s[10005],ss[10005],aa,bb;
const int mod=26;
unsigned int p[10005],pr[1000005],pp[1000005],po[10005],anss;
signed main(){
//	freopen("replace2.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	pr[0]=1;
	for(register int i=1;i<=1000005;i++){
		pr[i]=pr[i-1]*mod;
	}
	for(register int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
		for(register int j=s[i].size()-1;j>=0;j--){
			int c=s[i][j]-'a'+1;
	//		cout<<c<<"\n";
			p[i]=p[i]+c*pr[s[i].size()-1-j];
		}
	//	cout<<p[i]<<'\n';
		for(register int j=ss[i].size()-1;j>=0;j--){
			int c=ss[i][j]-'a'+1;
			po[i]=po[i]+c*pr[ss[i].size()-1-j];
		}
	}
	for(register int i=1;i<=q;i++){
		cin>>aa>>bb;
		anss=0;
		ans=0;
		for(register int j=aa.size();j>=0;j--){
			pp[j]=0;
		}
		pp[aa.size()]=aa[aa.size()-1]-'a'+1;
		for(register int j=aa.size()-1;j>0;j--){
			int c=aa[j-1]-'a'+1;
			pp[j]=pp[j+1]+pr[aa.size()-j]*c;
		}
		for(register int j=bb.size()-1;j>=0;j--){
			int c=bb[j]-'a'+1;
			anss=anss+pr[bb.size()-1-j]*c;
		}
		int ll=aa.size();
		for(register int j=1;j<=n;j++){
			int l=s[j].size();
			if(l>ll){
				continue;
			}
		//	cout<<anss<<'\n';
			for(register int k=1;k<=aa.size()-l+1;k++){
			//	cout<<p[j]*pr[aa.size()-k-l+1]<<" "<<pp[k]<<" "<<pp[k+l]<<" "<<po[j]*pr[aa.size()-k-l+1]<<'\n';
				if(pp[k]-pp[k+l]==p[j]*pr[aa.size()-k-l+1]){
					if(pp[1]-p[j]*pr[aa.size()-k-l+1]+po[j]*pr[aa.size()-k-l+1]==anss){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a

