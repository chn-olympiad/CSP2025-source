#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
string S1[N],S2[N],t1,t2;
int main(){
	std::freopen("replace.in","r",stdin);
	std::freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;++i) cin>>S1[i]>>S2[i];
	while(q--){
		cin>>t1>>t2;
		t1 = " "+t1;
		t2 = " "+t2;
		int x1 = t1.size();
		int x2 = t2.size();
		if(x1 ^ x2){
			cout<<0<<'\n';
			continue;
		}
		int ans = 0;
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=x1-S1[i].size()+1;++j){
				bool f1 = 1,f2 = 1;
				for(int k = j;k<=j+S1[i].size()-1;++k)
					if(t1[k] != S1[i][k-j]) f1 = 0;
				for(int k = j;k<=j+S1[i].size()-1;++k)
					if(t2[k] != S2[i][k-j]) f2 = 0;
				if(f1 && f2) ++ans;
				bool f3 = 1,f4 = 1;
				for(int k = 1;k<=j-1;++k) if(t1[i] != t2[i]) f3 = 0;
				for(int k = j+S1[i].size();k<=x2;++k) if(t1[i] != t2[i]) f4 = 0;
				if(f1&&f2&&f3&&f4)++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

