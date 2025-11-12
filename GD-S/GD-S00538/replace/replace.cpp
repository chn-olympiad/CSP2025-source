#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 1e5+7, b = 131;
int t[N][2],len[N];
int base[N],h1[N],h2[N];
void init(){
	base[0]=1;
	for(int i=1;i<N;i++){
		base[i]=b*base[i-1]; 
	}
}
void make_hash(string s,int h[]){
	h[0]=s[0]-'a';
	for(int i=1;i<s.size();i++){
		h[i]=h[i-1]+base[i]*(s[i]-'a');
	} 
}
int subhash(int l,int r,int h[]){
	if(l>r) return 0;
	return (h[r]-h[l-1])/base[l];
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin >> n >> q;
	init();
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		make_hash(s1,h1);
		make_hash(s2,h2);
		t[i][0]=h1[s1.size()-1];
		t[i][1]=h2[s2.size()-1];
		len[i]=s1.size();
	}
	while(q--){
		string s1,s2;
		cin >> s1 >> s2;
		if(s1.size()!=s2.size()){
			cout << "0\n";
			continue; 
		}
		int ans=0;
		make_hash(s1,h1);
		make_hash(s2,h2);
		for(int i=1;i<=n;i++){
			int l=len[i],t1=t[i][0],t2=t[i][1];
			if(l>s1.size()) continue; 
			for(int j=0;j<=s1.size()-l;j++){
				// 0~j-1 j~j+l-1 j+l~s1.size()-1
				if(subhash(0,j-1,h1)==subhash(0,j-1,h2)&&subhash(j+l,s1.size()-1,h1)==subhash(j+l,s1.size()-1,h2)&&subhash(j,j+l-1,h1)==t1&&subhash(j,j+l-1,h2)==t2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
