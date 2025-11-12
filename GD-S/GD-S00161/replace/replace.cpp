#include<bits/stdc++.h>
#define N 1015
#define ll long long
#define rd read()
#define gc getchar()
using namespace std;
int n,q,tot;
string s1,s2;
inline int read(){
	int x=0;char ch=gc;
	while(!('0'<=ch&&ch<='9')) ch=gc;
	while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=gc;
	return x;
}
map<string,int>mp;
int e[3005][3005];
inline int get(string s,int op){
	if(!mp[s]&&op) mp[s]=++tot;
	return mp[s];
}
inline ll sol(string s1,string s2){
	int m=s1.size();s1=' '+s1;s2=' '+s2;
	ll l=m,r=1,cnt=0;string t1,t2;
	for(int i=1;i<=m;i++){if(s1[i]!=s2[i]){l=i;break;}}
	for(int i=m;i>=1;i--){if(s1[i]!=s2[i]){r=i;break;}}
	for(int i=1;i<=l;i++){
		t1=t2=" ";
		for(int j=i;j<r;j++) t1=t1+s1[j],t2=t2+s2[j];
		for(int j=max(i,r);j<=m;j++){
			t1=t1+s1[j];t2=t2+s2[j];
			cnt+=e[get(t1,0)][get(t2,0)];
		}
	}
	return cnt;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd;q=rd;
	for(int i=1;i<=n;i++){cin>>s1>>s2;s1=' '+s1;s2=' '+s2;e[get(s1,1)][get(s2,1)]=1;}
	for(int i=1;i<=q;i++){cin>>s1>>s2;cout<<sol(s1,s2)<<'\n';}
	return 0;
}
/*
3 1
a a
aa aa
aaa aaa
aaa aaa
*/
