#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//priority_queue<pii,vector<pii>,greater<pii> > q;
ll read(){
	ll n=0;
	int f=1;
	char x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-')f=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9'){
		n=n*10+x-'0';
		x=getchar();
	}
	return n*f;
}
const int N=2e5;
int n;
struct pairz{
	string u,v;
}th[N+10];
int work(){
	string u,v;
	cin>>u>>v;
	int len=u.size();
	if(len!=int(v.size())){
		putchar('0');
		return 0;
	}
	int l=0,r=-1;
	for(int i=0;i<len;i++){//需要替换的区间 
		if(r<0)l=i;
		if(u[i]!=v[i])r=i;
	}
	ll ans=0;
	for(int i=0;i<len;i++){//[i,j]的区间就是要替换的
		for(int j=0;j<len;j++){
			string s1="",s2="";
			for(int k=i;k<=j;k++){
				s1+=u[k];
			}
			for(int k=i;k<=j;k++){
				s2+=v[k];
			}
			for(int k=1;k<=n;k++){
				if(th[k].u!=s1||th[k].v!=s2){
					continue;
				}
				if(i<=l&&j>=r)ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1!=s2){
			th[i]=pairz{s1,s2};
		}else{
			i--;
			n--;
		}
	}
	while(t--){
		work();
		if(t)putchar('\n');
	}
	return 0;
}/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*//*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
