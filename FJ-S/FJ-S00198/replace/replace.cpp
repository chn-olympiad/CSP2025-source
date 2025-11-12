#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
const ll L=5e6+10;
ll n,Q,a[1010][1010],b[1010][1010],len1[N],len2[N],vis[N],ans;
string s1[N],s2[N],str1,str2,str[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(ll k=1;k<=n;k++){
		cin>>s1[k]>>s2[k];
		str[k]=s2[k];
		len1[k]=s1[k].length();
		len2[k]=s2[k].length();
		s1[k]=' '+s1[k]; s2[k]=' '+s2[k];
		for(ll i=2,j=0;i<=len1[k];i++){
			while(j && s1[k][i]!=s1[k][j+1]) j=a[k][j];
			if(s1[k][i]==s1[k][j+1]) j++;
			a[k][i]=j; 
		}
		for(ll i=2,j=0;i<=len2[k];i++){
			while(j && s2[k][i]!=s2[k][j+1]) j=b[k][j];
			if(s2[k][i]==s2[k][j+1]) j++;
			b[k][i]=j; 
		}
	}
	while(Q--){
		cin>>str1>>str2;
		ll l1=str1.length(),l2=str2.length();
		ans=0;
		memset(vis,0,sizeof(vis));
		str1=' '+str1; str2=' '+str2;
		for(ll k=1;k<=n;k++){
			for(ll i=1,j=0;i<=l1;i++){
				while(j && str1[i]!=s1[k][j+1]) j=a[k][j];
				if(str1[i]==s1[k][j+1]) j++;
				if(j==len1[k]){
					string s=str1.substr(0,i-len1[k]+1)+str[k]+str1.substr(i+1);
//					cout<<s<<endl;
					if(s==str2){
						ans++;
						break;
					}
					j=a[k][j];
				}				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
