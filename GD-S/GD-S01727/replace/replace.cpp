#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct node{
	int l;
	int r;
	int len;
};
string s[200005][2];
string t[200005][2];
node ds[200005];
node dt[200005];
ull sums[200005][2];
ull power[5000005];
ull sumt[200005][2];
const ull p=182627; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	power[0]=1;
	for(int i=1;i<=5e6;i++){
		power[i]=power[i-1]*p;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=1;j<=s[i][0].size();j++){
			sums[i][0]=sums[i][0]*p+s[i][0][j-1];
			sums[i][1]=sums[i][1]*p+s[i][1][j-1];
		}
		ds[i].l=5e6;
		ds[i].r=-1;
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]!=s[i][1][j]){
				ds[i].l=min(ds[i].l,j);
				ds[i].r=max(ds[i].r,j);
			}
		}
		ds[i].len=ds[i].r-ds[i].l+1;
//		cout<<sums[i][0]<<' '<<sums[i][1]<<'\n';
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		for(int j=1;j<=t[i][0].size();j++){
			sumt[j][0]=sumt[j-1][0]*p+t[i][0][j-1];
			sumt[j][1]=sumt[j-1][1]*p+t[i][1][j-1];
		}
		dt[i].l=5e6;
		dt[i].r=-1;
		for(int j=0;j<t[i][0].size();j++){
			if(t[i][0][j]!=t[i][1][j]){
				dt[i].l=min(dt[i].l,j);
				dt[i].r=max(dt[i].r,j);
			}
		}
		dt[i].len=dt[i].r-dt[i].l+1;
//		cout<<dt[i].len<<'\n'; 
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(dt[i].len!=ds[j].len) continue;
			int l=dt[i].l-ds[j].l;
			int r=dt[i].r+s[j][0].size()-ds[j].r;
			if(l<0 || r>t[i][0].size()) continue;
//			cout<<j<<' '<<l<<' '<<r<<'\n';
			if(sumt[r][0]-sumt[l][0]*power[r-l]==sums[j][0] && 
				sumt[r][1]-sumt[l][1]*power[r-l]==sums[j][1]) cnt++;
		}
		cout<<cnt<<'\n';
	}
}
