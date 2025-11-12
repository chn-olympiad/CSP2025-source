//GZ-S00325 贵阳市第一中学 王梓竣 
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct nod{
	string s1;
	string s2;
}l[2000005];
int a,b,c,n,m,ans,tot,T,k;
int check(string a,string b,int sit){
	int len=0;
	for(int i=sit;i<min(a.length(),sit+b.length());i++){
		if(a[i]!=b[i-sit]){
			break;
		}
		len++;
	}
	if(len==b.length()){
		return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i].s1>>l[i].s2;
	}
	while(m--){
		string s1,s2;
		cin>>s1>>s2;
		ans=0;
		for(int i=0;i<s1.length();i++){
			for(int j=1;j<=n;j++){
				if(check(s1,l[j].s1,i)){
					string tmp=s1;
					for(int o=0;o<l[j].s2.length();o++){
						tmp[i+o]=l[j].s2[o];
					}
					if(check(tmp,s2,0)){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
