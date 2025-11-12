#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<unsigned long long> val(0,18446744073709551615ull);

const int N=2e5+10;
int n,q;
unsigned long long ch[26],B,BB[N];
vector<unsigned long long> a,b,s[N],t[N];
string ss,tt;
//umap<unsigned long long,int> mp;
//int nn[N]
int main(){
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	for(int i=0;i<26;i++)
//		ch[i]=val(rng);
//	B=val(rng);
	cin>>n>>q;
//	BB[0]=1;
//	for(int i=1;i<=n;i++)BB[i]=BB[i-1]*B;
	for(int i=1;i<=n;i++){
//		cin>>ss>>tt;
//		nn[i]=ss.size();
//		for(int o=1;o<=ss.size();o++)
//			s[i][o]=s[i][o-1]*B+ch[ss[o-1]-'a'];
//		for(int o=1;o<=tt.size();o++)
//			t[i][o]=t[i][o-1]*B+ch[tt[o-1]-'a'];
	}
	while(q--){
//		cin>>ss>>tt;
//		int tn=ss.size();
//		for(int o=1;o<=ss.size();o++)
//			a[o]=a[o-1]*B+ch[ss[o-1]-'a'];
//		for(int o=1;o<=tt.size();o++)
//			b[o]=b[o-1]*B+ch[tt[o-1]-'a'];
//		mp[a[o]]=1;
//		for(int i=1;i<=n;i++){
//			for(int o=1;o+nn[i]<=tn;o++)
//				if(a[o]*iv[])
//		}
		cout<<0<<endl;
	}
	return 0;
} 
