#include<bits/stdc++.h>
using namespace std;
const int N=5e6+50;
#define mkp make_pair 
int T=1;
int n,m,k,s,q;
int ans;
char s1[N],s2[N];
struct node{
	int sn[27],v;
}t[N];
int tot=0;
int newnode(){
	++tot;
	for(int i=0;i<27;i++)t[tot].sn[i]=0;
	t[tot].v=0;
	return tot;
}
int len;
int ins(int l,int r){
	int u=0;
	for(int i=l;i<=r;++i){
		if(!t[u].sn[s1[i]-'a'])t[u].sn[s1[i]-'a']=newnode();
		u=t[u].sn[s1[i]-'a'];
	}
	for(int i=l;i<=r;++i){
		if(!t[u].sn[s2[i]-'a'])t[u].sn[s2[i]-'a']=newnode();
		u=t[u].sn[s2[i]-'a'];
	}
	return u;
//	if(r==len-1)++t[u].v;
}
map<pair<int,int>,int> mp;
void solve(){
	mp.clear();
	scanf("%d%d",&n,&q);
//	cerr<<n<<" "<<q<<'\n'; 
	for(int i=1;i<=n;++i){
		int l,r;
		len=0;
		char c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
			s1[len++]=c;
			c=getchar();
		}
		len=0;
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
			s2[len++]=c;
			c=getchar();
		}
		for(l=0;l<len;l++)if(s1[l]!=s2[l])break;
		for(r=len-1;r>=l;--r)if(s1[r]!=s2[r])break;
		int u=ins(l,r);
		t[u].v++;
	}
	for(int i=1;i<=q;i++){
		int l,r,tmp;
		len=0;
		char c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
			s1[len++]=c;
			c=getchar();
		}
		tmp=len;
		len=0;
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
			s2[len++]=c;
			c=getchar();
		}
		if(tmp!=len){
			cout<<0<<'\n';
			continue;
		}
		for(l=0;l<len;l++)if(s1[l]!=s2[l])break;
		for(r=len-1;r>=l;--r)if(s1[r]!=s2[r])break;
		int u=ins(l,r);
		cout<<t[u].v<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	while(T--){solve();}
	return 0;
} 
