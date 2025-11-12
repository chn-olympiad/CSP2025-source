#include<bits/stdc++.h>
#define lp long long
using namespace std;
int n,q;
string cs1[200005],cs2[200005],s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>cs1[i]>>cs2[i];
	while(q--){
		cin>>s1>>s2;
		int ans=0;
		for(int i=1;i<=n;++i){
			int pos=s1.find(cs1[i]);
			int len=cs1[i].size();
			while(pos!=-1){
				string str=s1;
				str.replace(pos,len,cs2[i]);
				if(str==s2) ++ans;
				pos=s1.find(cs1[i],pos+1);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
