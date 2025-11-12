#include <bits/stdc++.h>
using namespace std;
int n,q,tot,ans[200005];
map<pair<string,string>,int> id;
map<pair<string,string>,bool> vis;
struct Node{
	int qid;
	string l,r;
};
vector<Node> a[400005];
string s,t;
bool subR(string a,string b){
	int lena=a.size(),lenb=b.size();
	if (lena>lenb) return 0;
	for (int i=0;i<lena;i++) if (a[lena-1-i]!=b[lenb-1-i]) return 0;
	return 1;
}
bool subL(string a,string b){
	int lena=a.size(),lenb=b.size();
	if (lena>lenb) return 0;
	for (int i=0;i<lena;i++) if (a[i]!=b[i]) return 0;
	return 1;
}
void work(string s,string t,int qid){
	int len=s.size(),l=1e9,r=0;
	for (int i=0;i<s.size();i++) if (s[i]!=t[i]) l=min(l,i),r=i;
	if (l==1e9) return;
	string resa="",resb="",L="",R="";
	for (int i=l;i<=r;i++) resa+=s[i],resb+=t[i];
	for (int i=0;i<l;i++) L+=s[i];
	for (int i=r+1;i<len;i++) R+=s[i];
	if (resa=="") return;
	if (!vis[{resa,resb}]) vis[{resa,resb}]=1,id[{resa,resb}]=++tot;
	int Id=id[{resa,resb}];
	if (qid<0) a[Id].push_back({qid,L,R});
	else{
		for (int i=0;i<a[Id].size();i++){
			if (subR(a[Id][i].l,L)&&subL(a[Id][i].r,R)){
				ans[qid]++;
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		cin>>s>>t,work(s,t,-i);
	}
	for (int i=1;i<=q;i++){
		cin>>s>>t;
		work(s,t,i);
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
