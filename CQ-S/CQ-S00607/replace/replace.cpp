#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5e6+1,base=31;
int T,n,m,ans;
string s,t;
ull x,y,p[N],a[N],b[N];
unordered_map<ull,unordered_multiset<ull>>mp;
inline ull A(int l,int r){
	return a[r]-a[l-1]*p[r-l+1];
}
inline ull B(int l,int r){
	return b[r]-b[l-1]*p[r-l+1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m,p[0]=1;
	for(int i=1;i<=5e6;i++)p[i]=p[i-1]*base;
	for(int i=1;i<=n;i++){
		cin>>s>>t,x=y=0;
		for(int j=0;j<s.size();j++)x=x*base+s[j]-'a'+1,y=y*base+t[j]-'a'+1;
		mp[x].insert(y);
	}
	for(int i=1,l,r,d;i<=m;i++){
		cin>>s>>t,l=ans=0,r=s.size()-1,d=r+1;
		while(s[l]==t[l])l++;l++;
		while(s[r]==t[r])r--;r++;
		for(int j=0;j<d;j++)a[j+1]=a[j]*base+s[j]-'a'+1,b[j+1]=b[j]*base+t[j]-'a'+1;
		for(int j=1;j<=l;j++)
			for(int k=r;k<=d;k++){
				x=A(j,k),y=B(j,k);
				if(mp.find(x)!=mp.end())ans+=mp[x].count(y);
			}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
被抛弃的女孩，深渊中乞愿被爱
无法失去陪伴，被自己的愿望加害
变革疯狂时代，虚构爱恋的梦幻
罪孽于斯转圜，指向空洞的未来
不忠错觉，痼病随着她的选择消解
妄想灰飞烟灭，回归最初的起点
一场梦魇，潜意识也被执念所欺骗
最后一个章节，面对现实睁开眼 
*/
