#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10,M=1e6+10,mod=1e9+7;
int n,q;
char s[N],t[N];
map<pair<int,int>,int> mp;
int cnt;
map<int,bitset<N> > mp1[N],mp2[N];
bitset<N> ans1,ans2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s,t);
		ll s1=0,a=0,b=0,t1=0;
		int len=strlen(s),l=-1,r=0;
		for(int j=0;j<len;j++){
			if(s[j]!=t[j]){
				if(l==-1) l=j;
				r=j;
			}
		}
		for(int j=l-1;j>=0;j--)a=(a*114+s[j]-'a')%mod;
		for(int j=l;j<=r;j++){
			s1=(s1*114+s[j]-'a')%mod;
			t1=(t1*114+t[j]-'a')%mod;
		}
		for(int j=r+1;j<len;j++) b=(b*114+s[j]-'a')%mod;
		if(!mp[make_pair(s1,t1)]) mp[make_pair(s1,t1)]=++cnt;
		mp1[mp[make_pair(s1,t1)]][a].set(i);
		mp2[mp[make_pair(s1,t1)]][b].set(i);	
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",s,t);
		if(strlen(s)!=strlen(t)){printf("0\n");continue;}
		ll s1=0,t1=0;
		int len=strlen(s),l=-1,r=0;
		for(int j=0;j<len;j++){
			if(s[j]!=t[j]){
				if(l==-1) l=j;
				r=j;
			}
		}
		for(int j=l;j<=r;j++){
			s1=s1*114+s[j]-'a';s1%=mod;
			t1=t1*114+t[j]-'a';t1%=mod;
		}
		int k=mp[make_pair(s1,t1)];
		if(!k){printf("0\n");continue;}
		ans1=0;ans2=0;
		ans1|=mp1[k][0];ans2|=mp2[k][0];
		ll aa=0,bb=0;
		for(int j=l-1;j>=0;j--){
			aa=aa*114+s[j]-'a';aa%=mod;
			ans1|=mp1[k][aa];
		}
		for(int j=r+1;j<len;j++){
			bb=bb*114+s[j]-'a';bb%=mod;
			ans2|=mp2[k][bb];
		}
		printf("%d\n",(ans1&ans2).count());
	}
	return 0;
} 


