#include<bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define MAXQ 200005
using namespace std;
int n,q,ans;
string t,tt;
string s[MAXN][5];
string getstr(int l,int r,string ls){
	char ns[r-l];
	for(int i=l;i<r;++i)ns[i-l+1]=ls[i];
	return ns;
}
//void replacestring(int l,string ds,string &ls){//replacestringandget
//	for(int i=l;i<ds.size()+l;++i)ls[i]=ds[i-l];
//}
string rpstr(int l,string ds,string ls){//replacestringandget
	char ns[ls.size()];
	for(int i=0;i<ls.size();++i)
		if(i<l||i>=ds.size()+l)ns[i]=ls[i];
		else ns[i]=ds[i-l];
	return ns;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>s[i][1]>>s[i][2];
	while(q--){
		ans=0;
		cin>>t>>tt;
		for(int i=0;i<t.size();++i)
			for(int j=1;j<=n;++j)
				if(i+s[j][1].size()<=t.size())
					if(getstr(i,i+s[j][1].size(),t)==s[j][1])
						if(rpstr(i,s[j][2],t)==tt)
							ans++;
		cout<<ans<<"\n";
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
