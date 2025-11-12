#include<bits/stdc++.h>
using namespace std;
const int N=5e6;
int n,q,cnt,tim,special,res[200020],t[5000050],lst[5000050];
string s1[200020],s2[200020],t1[200020],t2[200020];
void check(){
	special=1;
	for(int i=1;i<=n;i++){
		int as=0,bs=0;
		for(char j:s1[i]){
			if(j=='a')as++;
			if(j=='b')bs++;
		}
		if(bs!=1||as+bs!=s1[i].size()){
			special=0;
			return ;
		}
		as=0,bs=0;
		for(char j:s2[i]){
			if(j=='a')as++;
			if(j=='b')bs++;
		}
		if(bs!=1||as+bs!=s2[i].size()){
			special=0;
			return ;
		}
	}
	for(int i=1;i<=q;i++){
		int as=0,bs=0;
		for(char j:t1[i]){
			if(j=='a')as++;
			if(j=='b')bs++;
		}
		if(bs!=1||as+bs!=t1[i].size()){
			special=0;
			return ;
		}
		as=0,bs=0;
		for(char j:t2[i]){
			if(j=='a')as++;
			if(j=='b')bs++;
		}
		if(bs!=1||as+bs!=t2[i].size()){
			special=0;
			return ;
		}
	}
}
struct query{
	int tp,id,x,y,z;
};
query qs[400040];
bool cmp(query a,query b){
	if(a.z!=b.z)return a.z<b.z;
	if(a.x!=b.x)return a.x<b.x;
	return a.tp<b.tp;
}
void add(int x,int y){
	while(x<=N){
		if(lst[x]!=tim)t[x]=0;
		t[x]+=y;lst[x]=tim;
		x+=(x&-x);
	}
}
int sum(int x){
	int res=0;
	while(x){
		if(lst[x]!=tim)t[x]=0;
		res+=t[x];lst[x]=tim;
		x-=(x&-x);
	} 
	return res;
}
void solve1(){
	for(int i=1;i<=n;i++){
		int b1=-1,b2=-1;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				b1=j;
				break;
			}
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b'){
				b2=j;
				break;
			}
		}
//		cerr<<b1<<' '<<b2<<'\n';
		qs[++cnt]={0,0,b1+1,(int)(s2[i].size()-b2+1),b1-b2};
	}
	for(int i=1;i<=q;i++){
		if(t1[i].size()!=t2[i].size())continue;
		int b1=-1,b2=-1;
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]=='b'){
				b1=j;
				break;
			}
		}
		for(int j=0;j<t2[i].size();j++){
			if(t2[i][j]=='b'){
				b2=j;
				break;
			}
		}
//		cerr<<b1<<' '<<b2<<'\n';
		qs[++cnt]={1,i,b1+1,(int)(t2[i].size()-b2+1),b1-b2};
	}
	sort(qs+1,qs+cnt+1,cmp);
	tim++;
	for(int i=1;i<=cnt;i++){
		if(qs[i].tp==0){
			add(qs[i].y,1);
		}
		else{
			res[qs[i].id]=sum(qs[i].y);
		}
		
		if(i==cnt||qs[i].z!=qs[i+1].z){
			tim++;
		}
	}
	for(int i=1;i<=q;i++)cout<<res[i]<<'\n';
}
void solve2(){
	for(int i=1;i<=q;i++){
		int ans=0,fstdif=-1,lstdif=-1;
		if(t1[i].size()!=t2[i].size()){
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<t1[i].size();j++){
			if(t1[i][j]!=t2[i][j]){
				if(fstdif==-1)fstdif=j;
				lstdif=j;
			}
		}
		for(int j=1;j<=n;j++){
			int fd2=-1,_=1;
			for(int k=0;k<s1[j].size();k++){
				if(s1[j][k]!=s2[j][k]){
					fd2=k;
					break;
				}
			}
			if(fd2==-1)continue; 
			if(lstdif>((int)(s1[j].size())-1+fstdif-fd2))continue;
			for(int k=0;k<s1[j].size();k++){
				int to=k+fstdif-fd2;
				if(to<0){
					_=0;
					break;
				} 
				if(s1[j][k]!=t1[i][to]||s2[j][k]!=t2[i][to]){
					_=0;
					break;
				}
			}
			ans+=_;
//			if(_)cerr<<j<<' ';
		}
		cout<<ans<<'\n';
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
	}
	check();
//	cerr<<special<<' ';
	if(special)solve1();
	else solve2();
	









	return 0;
}
/*

在字符串中找模式并替换，问能否变化为目标

等等这啥空间限制？？？

可以考虑 trie 树了

5000000*26*4=520000000

翻两倍

可以证明，对于一个替换规则，最多只会有一个位置能够使得这个替换规则成立

替换的长度必须至少是最远的两个不同的距离

qeiewueiwe 
qexewueywe 

例如这样子

然后替换的话 应该是位置对齐原理 也就是同样的 不同的第一个位置 进行对齐

然后可以哈希 

因为不对齐的话 肯定不合法

trie！

都找第一个对齐（不同）位置， 


SSSSSDSDDSDDSSDDDSDDSSSSSSSSSS

插入时，对于DSDDSDDSSDDDSDDSSSSSSSSSS插入，并在末尾的节点上添加一个“SSSSS的哈希值

查询时， 对于DSDDSDDSSDDDSDDSSSSSSSSSS寻找，从最后一个 D 以后开始，

性质 B：先给定若干三元组{a,b,c}，然后给定以下条件d,e,f，求三元组个数：

c=f

a<=d
b<=e

这不是我们二维书店吗？

那怎么做？离线下来吗？

先给定若干三元组{a,b,c}，然后给定以下条件d,e,f，求三元组个数：

c=f

a是d的后缀 
b是e的前缀 

 

或许不用哈希，因为总共字符数有限

A 性质做法：注意到对齐第一个位置，然后直接判断，单次最坏 O(输入量）

B 性质：二位书店，离线下来

 


注意到s1可以=s2，此时变为KMP模板

不，s1=s2时，没有贡献

SSSSSDSSSSSSSSDS
SSSSSSSSSSDSSSSSSSSDS


zi ti

11 11
b b
ba ba
aab baa
abaa aaab
baaaa aaaba
aaaaab aaaaab
aaaaaba baaaaaa
aaaaabaa aaaabaaa
aaabaaaaa abaaaaaaa
abaaaaaaaa aaaaaaaaab
aaaaaabaaaa aaaaabaaaaa
aaaaaaaabaaa aaaabaaaaaaa
aaaaaaaaaaaab aaaaaaaabaaaa
aaaaaaaabaaaaa aaaaaabaaaaaaa
aaaaaaaaaaaabaa aabaaaaaaaaaaaa
aaaaaaabaaaaaaaa aaaaaabaaaaaaaaa
baaaaaaaaaaaaaaaa aaaaabaaaaaaaaaaa
aaaaabaaaaaaaaaaaa aaaaaaaaaaaabaaaaa
aaaaaaaaaaaaaabaaaa abaaaaaaaaaaaaaaaaa
aaaaaaaaabaaaaaaaaaa aaaaaaabaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaab aaaaaaaaaaaaaaaaaaaba
aabaaaaaaaaaaaaaaaaaaa baaaaaaaaaaaaaaaaaaaaa

*/


