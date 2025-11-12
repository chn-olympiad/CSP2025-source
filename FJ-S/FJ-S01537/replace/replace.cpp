#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Code ios::sync_with_stdio(0);
#define with cin.tie(0);
#define ZhouShen cout.tie(0);
#define int long long
#define N 200010
using namespace std;
int n,q,ans;
string s[N],s2[N],t,t2;
void read(int&a){
	int s=0,w=1;
	char ch;
	ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-')w=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
		ch=getchar();
	}
	a=s*w;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Code with ZhouShen
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s2[i];
	}
	string tmp;
	while(q--){
		cin>>t>>t2;
		tmp=t;
		ans=0;
		for(int i=1,p;i<=n;i++){
			tmp=t;
			p=t.find(s[i]);
			if(p<t.size()){
				tmp.replace(p,s[i].size(),s2[i]);
				if(tmp==t2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

