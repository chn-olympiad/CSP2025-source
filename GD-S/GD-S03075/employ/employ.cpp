#include<bits/stdc++.h>
using namespace std;
int n,m,ans,c[501],p[501];
string s;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;++i)cin>>c[i];
	iota(p,p+n+1,0);
	do{
		int cnt=0,ret=0;
		for(int i=1;i<=n;++i){
			if(cnt>=c[p[i]])++cnt;
			else{
				if(s[i]=='1')++ret;
				else ++cnt;
			}
		}if(ret>=m)++ans;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
}
/*
It is 18:09 now,I surf 18170 meters.
I hope that Skyler_Yunxi can get lan gou.
sto Zyj6 orz
sto Skyler_Yunxi orz
sto __yuanhaoran orz
sto nauyng orz
sto sunxuanyu orz
sto AUSG orz
sto 1vegetable orz
sto winyei orz
sto 2024zxj orz
sto less_than orz
sto greater_than orz
sto zssyt orz
sto Harvey2024 orz
*/