#include <bits/stdc++.h>
using namespace std;
long long n,m,L1,L2,pw[200005],p=1e9+7,ans;
unsigned long long pw2[200005]; 
string s[200005][2],t[200005][2];
vector<long long> hs1[200005][4];
vector<unsigned long long> hs2[200005][4];
void hashing(int x){
	hs1[x][0].push_back(s[x][0][0]-'a'),hs1[x][1].push_back(s[x][1][0]-'a'),hs2[x][0].push_back(s[x][0][0]-'a'),hs2[x][1].push_back(s[x][1][0]-'a');
	for(int i=1;i<s[x][0].size();i++) hs1[x][0].push_back((hs1[x][0][i-1]*pw[1]+s[x][0][i]-'a')%p),hs1[x][1].push_back((hs1[x][1][i-1]*pw[1]+s[x][1][i]-'a')%p),hs2[x][0].push_back(hs2[x][0][i-1]*pw2[1]+s[x][0][i]-'a'),hs2[x][1].push_back(hs2[x][1][i-1]*pw2[1]+s[x][1][i]-'a');
}
void hashing2(int x){
	hs1[x][2].push_back(t[x][0][0]-'a'),hs1[x][3].push_back(t[x][1][0]-'a'),hs2[x][2].push_back(t[x][0][0]-'a'),hs2[x][3].push_back(t[x][1][0]-'a');
	for(int i=1;i<t[x][0].size();i++) hs1[x][2].push_back((hs1[x][2][i-1]*pw[1]+t[x][0][i]-'a')%p),hs1[x][3].push_back((hs1[x][3][i-1]*pw[1]+t[x][1][i]-'a')%p),hs2[x][2].push_back(hs2[x][2][i-1]*pw2[1]+t[x][0][i]-'a'),hs2[x][3].push_back(hs2[x][3][i-1]*pw2[1]+t[x][1][i]-'a');
}
int geths1(int x,int y,int l,int r){
	int sum=hs1[x][y][r];
	if(l>0) sum-=hs1[x][y][l-1]*pw[r-l+1]%p,sum=(sum+p)%p;
	return sum;
}
int geths2(int x,int y,int l,int r){
	int sum=hs2[x][y][r];
	if(l>0) sum-=hs2[x][y][l-1]*pw2[r-l+1];
	return sum;
}
int main() {
	srand(time(0));
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m,pw[0]=pw2[0]=1;
    for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1],L1+=s[i][0].size()+s[i][1].size();
	 for(int i=1;i<=m;i++) cin>>t[i][0]>>t[i][1],L2+=t[i][0].size()+t[i][1].size();
	 if(n<=1000 && max(L1,L2)<=2000){
    for(int i=1;i<=200000;i++) pw[i]=pw[i-1]*29%p,pw2[i]=pw2[i-1]*31;
    for(int i=1;i<=n;i++) hashing(i);
    for(int i=1;i<=m;i++){
    	hashing2(i),ans=0;
    	int l=1e9,r=-1e9;
    	for(int j=0;j<t[i][0].size();j++) if(t[i][0][j]!=t[i][1][j]) l=min(l,j),r=j;
    	for(int j=0;j<min(t[i][0].size(),l+1ull);j++) for(int k=1;k<=n;k++) if(j+s[k][0].size()<=t[i][0].size() && geths1(i,2,j,j+s[k][0].size()-1)==geths1(k,0,0,s[k][0].size()-1) && geths2(i,2,j,j+s[k][0].size()-1)==geths2(k,0,0,s[k][0].size()-1) && geths1(i,3,j,j+s[k][0].size()-1)==geths1(k,1,0,s[k][0].size()-1) && geths2(i,3,j,j+s[k][0].size()-1)==geths2(k,1,0,s[k][0].size()-1) && j+s[k][0].size()-1>=r) ans++;
	    cout<<ans<<'\n'; 
	}
}
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
