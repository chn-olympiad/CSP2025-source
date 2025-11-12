#include<bits/stdc++.h>
using namespace std;
int n,q;
const int base=29,MOD=1e9+7;
int s[200005][2];
map<int,int> mp;
string ss,w;
int chg(string ss){
	long long tmp=0;
	for(int i=0;i<ss.size();i++){
		tmp=tmp*base+(ss[i]-'a');
		tmp%=MOD;
	}
	return tmp;
}
string l,r;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss;
		s[i][0]=chg(ss);
		cin>>ss;
		s[i][1]=chg(ss);
		mp[s[i][0]]=s[i][1];
	}
	while(q--){
		cin>>l>>r;
		int lx=1e9,rx=-1;
		for(int i=0;i<l.size();i++){
			if(l[i]!=r[i]){
				lx=min(lx,i);
				rx=max(rx,i);
			}
		}
		int cnt=0;
		for(int i=0;i<lx;i++){
			int tmp=0,tmpp=0;
			for(int j=i;j<l.size();j++){
				tmp=tmp*base+l[j]-'a';
				tmp%=MOD;
				tmpp=tmpp*base+r[j]-'a';
				tmpp%=MOD;
				if(mp[tmp]==tmpp){
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	
	
	
	
	return 0;
}
