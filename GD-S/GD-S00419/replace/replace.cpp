#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 2000005
#define N 20005
int n,r,top,topp,ans[M],g,cntt,s,sum;
string a,b,c,e,d,f;
map<pair<string,string>,int>mp;
map<pair<int,pair<int,int> >,int>tr;
map<pair<int,int>,int>cnt,mpp;
queue<int>q[M];
void trie(int top,string e){
	int rt=0;
	cnt[{top,rt}]++;
	for(int i=0;i<e.length();i++){
		if(!tr[{top,{rt,e[i]-'a'}}])tr[{top,{rt,e[i]-'a'}}]=++topp;
		rt=tr[{top,{rt,e[i]-'a'}}];
		cnt[{top,rt}]++;
	}
}
void find(int top,int rt){
	sum+=cnt[{top,rt}];
	if(mpp[{top,cntt}]){
		while(!q[mpp[{top,cntt}]].empty()){
			int x=q[mpp[{top,cntt}]].front();
			q[mpp[{top,cntt}]].pop();
			ans[x]+=sum;
		}
	}
	for(int i=0;i<26;i++){
		cntt=cntt*27+i+1;
		if(tr[{top,{rt,i}}])find(top,tr[{top,{rt,i}}]);
		cntt/=27;
	}
	sum-=cnt[{top,rt}];
}
signed main(){
//	freopen("replace3.in","r",stdin);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&r);
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		int r=a.length()-1;
		c="",d="",e="";
		while(r!=-1&&a[r]==b[r]) r--;
		for(int i=r;i!=-1;i--) c+=a[i],d+=b[i];
		for(int i=r+1;i<a.length();i++) e+=a[i];
		if(mp[{c,d}]==0) mp[{c,d}]=++top;  
		trie(mp[{c,d}],e);
	}
	for(int i=1;i<=r;i++){
		cin>>a>>b;
		int l=0,r=a.length()-1;
		c="",d="",f="";
		while(a[l]==b[l]) l++;
		while(a[r]==b[r]) r--;
		for(int i=r;i>l;i--) c+=a[i],d+=b[i];
		int s=0;
		for(int i=r+1;i<a.length();i++) s=s*27+a[i]-'a'+1;
		for(int j=l;j!=-1;j--){
			c+=a[j],d+=b[j];
			if(!mpp[{mp[{c,d}],s}]) mpp[{mp[{c,d}],s}]=++g;
			q[mpp[{mp[{c,d}],s}]].push(i);
		}
	}
	e="";
	for(int i=1;i<=top;i++)find(i,0);
	for(int i=1;i<=r;i++) printf("%lld\n",ans[i]);
	return 0;
}
