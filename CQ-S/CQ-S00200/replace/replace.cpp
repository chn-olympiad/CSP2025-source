#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,minlen=1e18,cnt[214514];
string ss[214514],t[214514];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ss[i]>>t[i];
	}
//	cout<<"!!!!!";
	while(q--){
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			cnt[(int)(a[i]-'a'+1)]+=1;
		}int ans=0;
//		if(cnt[2]==1&&cnt[1]==(int)a.size()-1){
			for(int i=1;i<=n;i++){
				if(a==ss[i]&&t[i]==b){
					ans++;
					continue;
				}
				if(a.find(ss[i])){
					string aa=a;
					int x=a.find(ss[i]);
					for(int j=x;j<x+ss[i].size();j++){
						aa[j]=t[i][j-x]; 
					}
					if(aa==b){
						ans++;
					}
//					cout<<aa<<'\n';
				}
			}
			cout<<ans<<'\n';
//		}
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
/*
3 4
a b
b c
c d
aa bb 
aa b
a c
b a

*/
