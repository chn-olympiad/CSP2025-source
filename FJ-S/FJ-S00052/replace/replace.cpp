#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
string ta[maxn],tb[maxn];
string sa,sb;int t[maxn];
string tmpc[maxn],tmpd[maxn];
string tmpa,tmpb;
map<string,int> mp;
int len(string s){
	int ans=0;
	for(int i=1;i<=maxn-10;i++){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) ans=0;
		else{
			ans=i;break;
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>(ta[i])>>(tb[i]);int tn=len(ta[i])-1;
		int lq,lz,cnt=0;bool tp=true;
		//cout<<tn<<endl;
		for(int j=0;j<=tn;j++){
			if(ta[i][j]!=tb[i][j]){
				if(tp){
					lq=j;tp=false;
				}else lz=j;
			}
		}for(int j=lq;j<=lz;j++) tmpc[i][cnt++]=ta[i][j],tmpd[i][cnt]=tb[i][j];
		t[i]=cnt-1;//cout<<cnt<<endl;
		//cout<<tmpc[i][0]<<endl;
	}while(q--){
		cin>>(sa)>>(sb);int tn=len(sa)-1;
		int lq,lz,ans=0,cnt=0;bool tp=true;
		for(int j=0;j<=tn;j++){
			if(sa[j]!=sb[j]){
				if(tp){
					lq=j;tp=false;
				}else lz=j;
			}
		}for(int j=lq;j<=lz;j++) tmpa[cnt++]=sa[j],tmpb[cnt]=sb[j];
		for(int i=1;i<=n;i++){
			int tp=1;//cout<<tmpc[i][0]<<endl;
			if(cnt!=t[i]+1){tp=0;break;}
			//cout<<tn<<" "<<t[i]<<endl;
			for(int j=0;j<=int(t[i]);j++) if(tmpc[i][j]!=tmpa[j]||tmpd[i][j]!=tmpb[j]){tp=0;break;}
			//if(tp==1) cout<<i<<endl;
			ans+=tp; 
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
/*37375 27578
iuj iit
jnzspf vkyewp
nxuevbvp ddrdlzmy
vpeplmmye xsdqlspol
cvndka jlwmet
znnr fzcv
btweqfstl kfqtjotpb
f h
fvxgrpvh pjxbxglm
pxnyqbkdsh upuhuhrtag
oqgwykr iljzuvi
xrr nnl
hyfem bjoaj
*/
