#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define ull unsigned long long
#define endl '\n'
#define base 31
using namespace std;
constexpr int N=2e5+10,Len=5e6+10;
int n,m,len;
ull hn[N][2];
ull hashs[2][Len];
string a[N][2],s,t,b[N][2];
ull pows[Len];
ull gethash(string &b){
	ull res=0;
	int lena=b.size();
	for(int i=0;i<lena;i++)
		res=(res*base)+(b[i]-'a');
	return res;
}
inline ull gett(int num,int l,int r){
	return hashs[num][r]-(l==0?0:hashs[num][l-1]*pows[r-l+1]);
}
namespace stka{
	void solve(){
		for(int qq=1;qq<=m;qq++){
			s=b[qq][0],t=b[qq][1];
			len=s.size();
			int l=0,r=len-1,cnt=0;
			while(s[l]==t[l]&&l<len)++l;
			while(s[r]==t[r]&&r>0)--r;
			ull res=0,ress=0;
			for(int i=0;i<len;i++){
				res=res*base+(s[i]-'a');
				ress=ress*base+(t[i]-'a');
				hashs[0][i]=res,hashs[1][i]=ress;
			}
			for(int i=1,tl,tr,tlen;i<=n;i++){
				tlen=a[i][0].size();
				if(l+tlen-1<r||tlen>len)continue;
				tl=max(0,r-tlen+1);
				tr=tl+tlen-1;
				while(tl<=l&&tr<len){
					cnt+=(gett(0,tl,tr)==hn[i][0]&&gett(1,tl,tr)==hn[i][1]);
					++tl,++tr;
				}
			}
			cout<<cnt<<endl;
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("replace.in","r",stdin);
//	freopen("replace4.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>m;
	pows[0]=1;
	for(int i=1;i<=5000000;i++)pows[i]=pows[i-1]*base;
	
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
		hn[i][0]=gethash(a[i][0]);
		hn[i][1]=gethash(a[i][1]);
	}
	for(int i=1;i<=m;i++)
		cin>>b[i][0]>>b[i][1];
	return stka::solve(),0;




	return 0;
}

