#include<bits/stdc++.h>
using namespace std;
const int N=5000005;
int n,Q;
string s1[N],s2[N],t1[N],t2[N];
struct Note{
	int c1,c2,c,id,ans;
}t[N<<1];
int cnt[N<<1];
int ans[N];
void Solve(int l,int r){
	if(l==r) return ;
	int mid=l+r>>1;
	Solve(l,mid); Solve(mid+1,r);
	sort(t+l,t+mid+1,[&](Note A,Note B){
		return A.c2<B.c2;
	});
	sort(t+mid+1,t+r+1,[&](Note A,Note B){
		return A.c2<B.c2;
	});
	int p=l;
	for(int i=mid+1;i<=r;i++){
		while(p<=mid&&t[p].c2<=t[i].c2){
			if(t[p].id<=n) ++cnt[t[p].c]; 
			++p;
		} 
		if(t[i].id>n) ans[t[i].id-n]+=cnt[t[i].c];
	}
	p=l;
	for(int i=mid+1;i<=r;i++){
		while(p<=mid&&t[p].c2<=t[i].c2){
			if(t[p].id<=n) --cnt[t[p].c]; 
			++p;
		} 
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=Q;i++) cin>>t1[i]>>t2[i];
	if(n<=200&&Q<=200) {
		for(int i=1;i<=Q;i++){
			if(t1[i].size()!=t2[i].size()) {
				puts("0"); continue;
			} 
			int ans=0;
			for(int j=0;j<t1[i].size();j++){
				if(j>0&&t1[i][j-1]!=t2[i][j-1]) break;
				for(int k=t1[i].size()-1;k>=j;k--){
					if(k<t1[i].size()-1&&t1[i][k+1]!=t2[i][k+1]) break;
					string x="",z="";
					string xx="",zz="";
					for(int w=0;w<j;w++) x+=t1[i][w],xx+=t2[i][w];
					for(int w=k+1;w<t1[i].size();w++) z+=t1[i][w],zz+=t2[i][w];
					if(x!=xx||z!=zz) continue;
					for(int w=1;w<=n;w++) if(x+s1[w]+z==t1[i]&&xx+s2[w]+z==t2[i]) ++ans;
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	} else {
		for(int i=1;i<=n;i++){
			int pos1,pos2;
			for(int j=0;j<s1[i].size();j++) if(s1[i][j]=='b') pos1=j;
			for(int j=0;j<s2[i].size();j++) if(s2[i][j]=='b') pos2=j;
			t[i]={pos1,int(s1[i].size())-pos1,pos2-pos1+N,i,0};
		}
		for(int i=1;i<=Q;i++){
			int pos1,pos2;
			for(int j=0;j<t1[i].size();j++) if(t1[i][j]=='b') pos1=j;
			for(int j=0;j<t2[i].size();j++) if(t2[i][j]=='b') pos2=j;
			t[i+n]={pos1,int(t1[i].size())-pos1,pos2-pos1+N,i+n,0};
		}
		sort(t+1,t+n+Q+1,[&](Note A,Note B){
			return A.c1==B.c1?A.id<B.id:A.c1<B.c1;
		});
		Solve(1,n+Q);
		for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	}
	return 0;
} 
