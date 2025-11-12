#include<bits/stdc++.h>
#define ll long long
#define R register
#define PII pair<int,int>
#define mk(x,y) make_pair(x,y)
#define ull unsigned ll
using namespace std;
const int N=2005,base=1331;
int n,q;
string s1[N],s2[N];
string t1,t2;
ull mul[N],hsh1[N],hsh2[N];
ull Has[N];
inline ull gethash(int l,int r){if(l>r)return 0;return Has[r]-Has[l-1]*mul[r-l+1];}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;mul[0]=1;
	for(R int i=1;i<N;++i)mul[i]=mul[i-1]*base;
	for(R int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		s1[i]=" "+s1[i],s2[i]=" "+s2[i];
		ull tmp1=0,tmp2=0;
		for(R int j=1;j<=len;++j){
			tmp1=(tmp1*base+s1[i][j]-'a'+1);
			tmp2=(tmp2*base+s2[i][j]-'a'+1);
		}
		hsh1[i]=tmp1,hsh2[i]=tmp2;
	}
	while(q--){
		cin>>t1>>t2;
		int len=t1.size();
		t1=" "+t1,t2=" "+t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";continue;
		}
		ull tmp2=0;
		Has[len+1]=0;
		for(R int i=1;i<=len;++i){
			Has[i]=Has[i-1]*base+t1[i]-'a'+1;
			tmp2=tmp2*base+t2[i]-'a'+1;
		}
		ll res=0;
		for(R int i=1;i<=n;++i){
			int lq=s1[i].size()-1;
			for(R int j=1;j+lq-1<=len;++j){
				if(gethash(j,j+lq-1)==hsh1[i]){
					ull to=Has[j-1]*mul[len-j+1]+hsh2[i]*mul[len-(j+lq-1)]+gethash(j+lq,len);
					if(to==tmp2)++res;
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}