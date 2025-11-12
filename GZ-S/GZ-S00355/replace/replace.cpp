// GZ-S00355 程袁浩 华师一 
#include <bits/stdc++.h>
#define int long long
#define upp(a,x,y) for(int a=x;a<=y;a++)
#define dww(a,x,y) for(int a=x;a>=y;a--)
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
const int N=5e6+10,X1=998244353,X2=1e9+7,M=2e5+10;
PII h[N];
vector<PII> f1[M],f2[M];
int llen[M];
int n,q;
void init() {
	h[0].x=h[0].y=1;
	upp(i,1,N-1) {
		h[i].x=h[i-1].x*131%X1;
		h[i].y=h[i-1].y*131%X2;
	}
} 
void ge(vector<PII> &f,int len,string str) {
	f.resize(len+1);
	f[0].x=f[0].y=0;
	upp(i,1,len) {
		f[i].x=(f[i-1].x*131+(str[i]-'a'+1))%X1;
		f[i].y=(f[i-1].y*131+(str[i]-'a'+1))%X2;
	}
}
PII qry(vector<PII> &f,int l,int r) {
	return {((f[r].x-f[l-1].x*h[r-l+1].x)%X1+X1)%X1,((f[r].y-f[l-1].y*h[r-l+1].y)%X2+X2)%X2};
}
void solve() {
	init();
    cin>>n>>q;
    upp(i,1,n) {
    	string str1,str2;cin>>str1>>str2;
    	str1=' '+str1,str2=' '+str2;
    	llen[i]=str1.size()-1;
    	ge(f1[i],llen[i],str1);
    	ge(f2[i],llen[i],str2);
	}
	upp(i,1,q) {
		string str1,str2;cin>>str1>>str2;
		if(str1.size()!=str2.size()) {
			cout<<0<<endl;
			continue;
		}
    	str1=' '+str1,str2=' '+str2;
		vector<PII> f3,f4;
    	ge(f3,str1.size()-1,str1);
    	ge(f4,str2.size()-1,str2);
    	int len=str1.size()-1;
    	int ans=0;
    	upp(j,1,n) {
    		upp(k,1,len) {
    			if(k>=llen[j]) {
    				if(qry(f3,1,k-llen[j])!=qry(f4,1,k-llen[j])) continue;
    				if(qry(f3,k+1,len)!=qry(f4,k+1,len)) continue;
    				//cout<<j<<' '<<k<<' '<<qry(f1[j],1,llen[j]).x<<' '<<qry(f1[j],1,llen[j]).y<<' '<<qry(f3,k-llen[j]+1,k).x<<' '<<qry(f3,k-llen[j]+1,k).y<<endl;
    				if(qry(f1[j],1,llen[j])!=qry(f3,k-llen[j]+1,k)) continue;
    				if(qry(f2[j],1,llen[j])!=qry(f4,k-llen[j]+1,k)) continue;
    				ans++;
    				break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int tt;tt=1;
    while(tt--) solve();
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

*/
