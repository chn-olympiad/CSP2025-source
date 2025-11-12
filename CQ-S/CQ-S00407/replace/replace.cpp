#include <bits/stdc++.h>
using namespace std;
int n,q;
const long long mod1=998244353,mod2=19491001,p1=131,p2=113;
string A,B;
struct SJ{
	int has1[2],has2[2];
	int len1,len2;
}sj[1000005];
map<pair<pair<int,int>,pair<int,int>>,int> mms;
pair<int,int> mma,mmb;
int cnt,nex[1000005],to[1000005];
void add(pair<pair<int,int>,pair<int,int>> u,int v){
	cnt++,nex[cnt]=mms[u],mms[u]=cnt,to[cnt]=v;
}
long long qzh[5000005][2],cj[5000005][2];
int pd(long long has1,long long has2,int l,int r){
	if(l>r){
		if(has1==0&&has2==0)return 1;
		return 0;
	}
	long long js1=0,js2=0;
	js1=(qzh[r][0]-qzh[l-1][0]*cj[r-l+1][0]%mod1+mod1)%mod1;
	js2=(qzh[r][1]-qzh[l-1][1]*cj[r-l+1][1]%mod2+mod2)%mod2;
	if(has1==js1&&has2==js2)return 1;
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>A>>B;
		int len=A.size(),wza=0,wzb=len+1;
		A=' '+A,B=' '+B;
		for(int i=1;i<=len;i++){
			if(A[i]==B[i])wza=i;
			else break;
		}
		for(int i=len;i>=1;i--){
			if(A[i]==B[i])wzb=i;
			else break;
		}
		if(wza<wzb){
			sj[i].len1=wza,sj[i].len2=len-wzb+1;
			long long js1=0,js2=0;
			for(int i=1;i<=wza;i++){
				js1=(js1*p1%mod1+A[i])%mod1;
				js2=(js2*p2%mod2+A[i])%mod2;
			}
			sj[i].has1[0]=js1,sj[i].has1[1]=js2;
			js1=0,js2=0;
			for(int i=wzb;i<=len;i++){
				js1=(js1*p1%mod1+A[i])%mod1;
				js2=(js2*p2%mod2+A[i])%mod2;
			}
			sj[i].has2[0]=js1,sj[i].has2[1]=js2;
			js1=0,js2=0;
			for(int i=wza+1;i<=wzb-1;i++){
				js1=(js1*p1%mod1+A[i])%mod1;
				js2=(js2*p2%mod2+A[i])%mod2;
			}
			mma=make_pair(js1,js2);
			js1=0,js2=0;
			for(int i=wza+1;i<=wzb-1;i++){
				js1=(js1*p1%mod1+B[i])%mod1;
				js2=(js2*p2%mod2+B[i])%mod2;
			}
			mmb=make_pair(js1,js2);
			add(make_pair(mma,mmb),i);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>A>>B;
		if(A.size()!=B.size())cout<<0<<'\n';
		else{
			int len=A.size(),wza=0,wzb=len+1;
			A=' '+A,B=' '+B;
			for(int i=1;i<=len;i++){
				if(A[i]==B[i])wza=i;
				else break;
			}
			for(int i=len;i>=1;i--){
				if(A[i]==B[i])wzb=i;
				else break;
			}
			int len1=wza,len2=len-wzb+1;
			long long js1=0,js2=0;
			for(int i=wza+1;i<=wzb-1;i++){
				js1=(js1*p1%mod1+A[i])%mod1;
				js2=(js2*p2%mod2+A[i])%mod2;
			}
			mma=make_pair(js1,js2);
			js1=0,js2=0;
			for(int i=wza+1;i<=wzb-1;i++){
				js1=(js1*p1%mod1+B[i])%mod1;
				js2=(js2*p2%mod2+B[i])%mod2;
			}
			mmb=make_pair(js1,js2);
			for(int i=1;i<=len;i++){
				qzh[i][0]=(qzh[i-1][0]*p1%mod1+A[i])%mod1;
				qzh[i][1]=(qzh[i-1][1]*p2%mod2+A[i])%mod2;
			}
			cj[0][0]=cj[0][1]=1;
			for(int i=1;i<=len;i++){
				cj[i][0]=cj[i-1][0]*p1%mod1;
				cj[i][1]=cj[i-1][1]*p2%mod2;
			}
			int sc=0;
			for(int k=mms[make_pair(mma,mmb)];k!=0;k=nex[k]){
				int v=to[k];
				if(sj[v].len1<=len1&&sj[v].len2<=len2){
					if(pd(sj[v].has1[0],sj[v].has1[1],wza-sj[v].len1+1,wza)&&pd(sj[v].has2[0],sj[v].has2[1],wzb,wzb+sj[v].len2-1))sc++;
				}
			}
			cout<<sc<<'\n';
		}
	}
	return 0;
}
