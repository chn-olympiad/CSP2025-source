//T3-target pts
#include<bits/stdc++.h>
//#define int long long
#define N 10005
using namespace std;
typedef unsigned long long ull;
ull n,q,base=131,h[N],b[N];
string t0,t1,s[N][2],g;
ull has(string a){
	ull sum=0;
	for(int i = 0; i < a.size(); i++ ){
		sum=sum*base+(a[i]-'a');
	}
	return sum;
}
void has2(string a){
	b[0]=a[0]-'a';
	for(int i = 1; i < a.size(); i++ ){
		b[i]=b[i-1]*base+(a[i]-'a');
	}
}
ull gethas(int l, int r){
	return b[r]-b[l-1]*pow(base,r-l);
}
signed main(){
	freopen("replace1.in","r",stdin);
//	freopen("replace.out","w",stdout);
//	system("fc road5.ans road.out");
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; i++ ){
		cin>>s[i][0]>>s[i][1];
		h[i]=has(s[i][0]);
//		cout<<h[i]<<' ';
	}
	while(q--){
		cin>>t0>>t1;
		if(t0.size()!=t1.size()){
			cout<<"0\n";
			continue;
		}
		has2(t0);
		cout<<b[1]<<' '<<b[2]<<'\n';
		cout<<h[2]<<' '<<gethas(1,s[2][0].size())<<'\n';
		for(int i = 1; i <= n; i++ ){
			for(int j = 0; j+s[i][0].size()<=t0.size(); j++ ){
				if(gethas(j+1,j+s[i][0].size())==h[i]){
					cout<<i<<' '<<j<<'\n';
//					g=t0.substr(0,j-1)+s[i][1]+t0.substr(j+s[i][0].size());
//					cout<<g<<' ';
				}
			}
		}
	}
	return 0;
}
