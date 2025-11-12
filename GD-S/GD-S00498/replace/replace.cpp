#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
const int mod=993244853;
int n,q,len,L1,L2,l,r,pl,pr,ans,cntg,cntd,maxn,nxt[N],res[N];
unsigned long long Hash;
char a[M],b[M];
bool flag=1;
vector<char> s1[N],s2[N],t1[N],t2[N];
vector<int> asd[M];
unordered_map<unsigned long long,int> mp;
struct node{
	int id,numl,numr,len,p;
};
node g[N],d[N];
bool cmp(node a,node b){
	if(a.len!=b.len) return a.len<b.len;
	return a.p<b.p;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",a,b);
		len=strlen(a);
		s1[i].resize(len);
		s2[i].resize(len);
		for(int j=0;j<len;j++){
			s1[i][j]=a[j];
			s2[i][j]=b[j];
			flag=flag&&(a[j]=='a'||a[j]=='b');
			flag=flag&&(b[j]=='a'||b[j]=='b');
		}
		L1+=2*len;
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",a,b);
		len=strlen(a);
		t1[i].resize(len);
		for(int j=0;j<len;j++) t1[i][j]=a[j],flag=flag&&(a[j]=='a'||a[j]=='b');
		L2+=len;
		len=strlen(b);
		t2[i].resize(len);
		for(int j=0;j<len;j++) t2[i][j]=b[j],flag=flag&&(b[j]=='a'||b[j]=='b');
		L2+=len;
	}
	if(L1<=2000&&L2<=2000){
		for(int i=1;i<=n;i++){
			Hash=0;
			for(int j=0;j<s1[i].size();j++){
				Hash*=1000000007;
				Hash+=s1[i][j]*1331+s2[i][j]*2003;
			}
			mp[Hash]++;
		}
		for(int i=1;i<=q;i++){
			if(t1[i].size()!=t2[i].size()){
				printf("0\n");
				continue;
			}
			l=r=-1;
			for(int j=0;j<t1[i].size();j++) if(t1[i][j]!=t2[i][j]){
				if(l==-1) l=j;
				r=j;
			}
			ans=0;
			for(int j=0;j<=l;j++){
				Hash=0;
				for(int k=j;k<r;k++){
					Hash*=1000000007;
					Hash+=t1[i][k]*1331+t2[i][k]*2003;
				}
				for(int k=r;k<t1[i].size();k++){
					Hash*=1000000007;
					Hash+=t1[i][k]*1331+t2[i][k]*2003;
					ans+=mp[Hash];
				}
			}
			printf("%d\n",ans);
		}
	}
	else if(flag){
		for(int i=1;i<=n;i++){
			l=r=-1;
			for(int j=0;j<s1[i].size();j++) if(s1[i][j]!=s2[i][j]){
				if(l==-1) l=j;
				r=j;
			}
			if(l==-1&&r==-1) continue;
			g[++cntg]=(node){i,l,(int)s1[i].size()-r-1,r-l+1,(int)(s1[i][l]=='a')};
		}
		for(int i=1;i<=q;i++){
			if(t1[i].size()!=t2[i].size()) continue;
			l=r=-1;
			for(int j=0;j<t1[i].size();j++) if(t1[i][j]!=t2[i][j]){
				if(l==-1) l=j;
				r=j;
			}
			d[++cntd]=(node){i,l,(int)t1[i].size()-r-1,r-l+1,(int)(t1[i][l]=='a')};
		}
		sort(g+1,g+cntg+1,cmp);
		sort(d+1,d+cntd+1,cmp);
		for(int i=1,p=1,q=1;i<=5000000;i++){
			for(int j=0;j<2;j++){
				maxn=0;
				while(p<=cntg&&g[p].len==i&&g[p].p==j){
					asd[g[p].numl].push_back(g[p].numr);
					maxn=max(maxn,g[p].numl);
					p++;
				}
				for(int k=0;k<=maxn;k++) if(!asd[k].empty()) sort(asd[k].begin(),asd[k].end());
				while(q<=cntd&&d[q].len==i&&d[q].p==j){
					for(int k=0;k<=d[q].numl;k++) if(!asd[k].empty()) res[d[q].id]+=upper_bound(asd[k].begin(),asd[k].end(),d[q].numr)-asd[k].begin();
					q++;
				}
				for(int k=0;k<=maxn;k++) if(!asd[k].empty()) asd[k].clear();
			}
		}
		for(int i=1;i<=q;i++) printf("%d\n",res[i]);
	}
	else{
		for(int i=1;i<=q;i++){
			if(t1[i].size()!=t2[i].size()){
				printf("0\n");
				continue;
			}
			l=r=-1;
			for(int j=0;j<t1[i].size();j++) if(t1[i][j]!=t2[i][j]){
				if(l==-1) l=j;
				r=j;
			}
			ans=0;
			for(int j=1;j<=n;j++){
				pl=pr=-1;
				for(int k=0;k<s1[j].size();k++) if(s1[j][k]!=s2[j][k]){
					if(pl==-1) pl=k;
					pr=k;
				}
				if(pl==-1&&pr==-1) continue;
				if(r-l+1!=pr-pl+1) continue;
				if(pl>l||(int)s1[j].size()-pr>(int)t1[i].size()-r) continue;
				flag=1;
				for(int k=0;k<s1[j].size();k++) if(s1[j][k]!=t1[i][k+l-pl]||s2[j][k]!=t2[i][k+l-pl]) flag=0;
				if(flag) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
