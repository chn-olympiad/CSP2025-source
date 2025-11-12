#include<bits/stdc++.h>

using namespace std;

#define int long long

int n,q;
string t1[200010],t2[200010];
string s1[200010],s2[200010];

signed main(){
	//freopen("replace4.in","r",stdin);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		if(n*q>=100000){
			puts("0");
			continue;
		}
		for(int j=1;j<=n;j++){
			int lt=t1[j].size();
			if(t1[j].size()>len) continue;
			for(int k=0;k<=len-lt;k++){
				
				//printf("qwqw %d %d %d %d %d %d\n",len-1-t1[j].size(),i,j,k,len,t1[j].size());
				
				if(s1[i].substr(k,lt)!=t1[j]) continue;
				if(s1[i].substr(0,k)+t2[j]+s1[i].substr(k+lt,len-(k+lt)+1)==s2[i]){
					ans++;
					//printf("qwq %d\n",j);
				}
			}
		}
		cout<<ans<<endl;
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

4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

*/
