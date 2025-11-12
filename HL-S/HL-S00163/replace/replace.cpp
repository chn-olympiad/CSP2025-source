#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct ST{
	int a,b,c,d;
}s[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int len1=s1.length(),len2=s2.length();
		s1=' '+s1,s2=' '+s2;
		bool flag=false;
		for(int j=1;j<=len1;j++){
			if(s1[j]=='b'){
				flag=true;
				continue;
			}
			if(!flag) s[i].a++;
			else s[i].b++;
		}
		flag=false;
		for(int j=1;j<=len2;j++){
			if(s2[j]=='b'){
				flag=true;
				continue;
			}
			if(!flag) s[i].c++;
			else s[i].d++;
		}		
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len1=s1.length(),len2=s2.length();
		s1=' '+s1,s2=' '+s2;
		bool flag=false;
		int aa=0,bb=0,cc=0,dd=0,ans=0;
		for(int j=1;j<=len1;j++){
			if(s1[j]=='b'){
				flag=true;
				continue;
			}
			if(!flag) aa++;
			else bb++;
		}
		flag=false;
		for(int j=1;j<=len2;j++){
			if(s2[j]=='b'){
				flag=true;
				continue;
			}
			if(!flag) cc++;
			else dd++;
		}
		for(int i=1;i<=n;i++) if(aa>=s[i].a&&bb>=s[i].b&&aa-cc==s[i].a-s[i].c) ans++;	
		cout<<ans<<"\n";	
	}
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
