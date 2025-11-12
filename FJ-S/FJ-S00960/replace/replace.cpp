#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,q,len[N];
string s1[N],s2[N],t1,t2;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
inline bool check(int l,int r,string s){
	for(int i=l,t=0;i<=r;i++,t++)
		if(t1[i]!=s[t]) return 0;
	return 1;
}
inline void huan(string &s,int l,int r,string st){
	for(int i=l,t=0;i<=r;i++,t++) s[i]=st[t];
}
inline void solve1(){
	while(q--){
		cin >> t1 >> t2;
		int l=t1.length(),ans=0;
		for(int i=0;i<l;i++){
			for(int j=1;j<=n;j++){
				if(check(i,i+len[j]-1,s1[j])){
					string tmp=t1;
					huan(tmp,i,i+len[j]-1,s2[j]);
					if(tmp==t2) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
inline void solve2(){
	bool flag1=0,flag=0;
	int cnt1[N]={},cnt2[N]={},cnt3[N]={},sum=0;
	for(int i=1;i<=n;i++){
		int top1,top2;
		for(int j=0;j<len[i];j++){
			if(s1[i][j]=='b') top1=j;
			if(s2[i][j]=='b') top2=j;
		}
		top1++,top2++;
		cnt1[i]=min(top1,top2)-1;
		cnt2[i]=top2-top1;
		cnt3[i]=len[i]-max(top1,top2);
	}
	while(q--){
		cin >> t1 >> t2;
		int l=t1.length(),pos1,pos2,ans=0;
		for(int i=0;i<l;i++)
			if(t1[i]=='b') pos1=i;
			else if(t2[i]=='b') pos2=i;
		for(int i=1;i<=n;i++)
			if(cnt1[i]<=min(pos1,pos2) && cnt3[i]<l-max(pos1,pos2) && cnt2[i]==pos2-pos1) ans++;
		printf("%d\n",ans);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) cin >> s1[i] >> s2[i];
	for(int i=1;i<=n;i++) len[i]=s1[i].length();
	if(n<=200 && q<=200) solve1();
	else solve2();
	return 0;
}
