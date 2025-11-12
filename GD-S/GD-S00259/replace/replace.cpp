#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,q,ans;
string s1[N+10],s2[N+10],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string str1,str2;
		cin>>str1>>str2;
		int l=0,r=str1.size()-1;
		for(;str1[l]==str2[l];l++);
		for(;str1[r]==str2[r];r--);
		for(int j=l;j<=r;j++){
			s1[i]+=str1[j];
			s2[i]+=str2[j];
		}
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int l=0,r=t1.size()-1;
		for(;t1[l]==t2[l];l++);
		for(;t1[r]==t2[r];r--);
		for(int i=1;i<=n;i++){
			if(r-l+1!=s1[i].size()){
				continue;
			}
			bool bo=0;
			for(int j=l;j<=r;j++){
				if(t1[j]!=s1[i][j-l]||t2[j]!=s2[i][j-l]){
					bo=1;
					break;
				}
			}
			if(bo==0){
				ans++;
			}
		}
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

2
0

3 4
a b
b c
c d
aa bb
aa b
a c
b a

0
0
0
0
*/ 
