#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
// remember to use return with han'shu
const int N=2e5+10;
int n,q,ans;
string s[N][3],t1,t2;
int check(const string& x,int l,const string& y){
	int l1=x.size(),l2=y.size(),i;
	for(i=0;i<l2;i++){
		if(x[l+i]!=y[i]) return -1;
	}
	return l+i-1;
}
void calc(const string x){
	int len=x.size();
	For(i,0,len-1){
		For(j,1,n){
			if(x[i]==s[j][1][0]){
				int l=i,r=check(x,l,s[j][1]);
				if(r==-1) continue;
				if(x.substr(0,l)+s[j][2]+x.substr(r+1,len)==t2) ans++;
			}
		}
	}
	return ;
}
signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	For(i,1,n) cin>>s[i][1]>>s[i][2];
	while(q--){
		ans=0;
		cin>>t1>>t2;
		calc(t1);
		cout<<ans<<endl;
	}
	return 0;
}
