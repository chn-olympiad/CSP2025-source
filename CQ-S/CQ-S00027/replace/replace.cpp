#include<bits/stdc++.h>
#include<unordered_map>
#define ll unsigned long long
#define LL __int128
#define db double
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define low lower_bound
#define upp upper_bound
using namespace std;
namespace hwq{
	inline int read(){int x=0;bool f=0;char ch=getchar();while(!isdigit(ch)&&ch!='-') ch=getchar();if(ch=='-') f=1,ch=getchar();while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-48,ch=getchar();return f?-x:x;}
	const int MAXN=5e6+5;
	const int MAXM=2e5+5;
	int n,q;
	int L[MAXM],R[MAXM];
	ll Hash1[MAXM],Hash2[MAXM],base[MAXN];
	char s[MAXN],t[MAXN];
	unordered_map<ll,unordered_map<ll,vector<int> > >mp;
	ll hash[MAXN];
	int main(){
		n=read(),q=read();
		for(int i=1,len;i<=n;i++){
			scanf("%s%s",s+1,t+1),len=strlen(s+1);
			int l=1,r=len;
			while(l<=len&&s[l]==t[l]) l++;
			while(r>=1&&s[r]==t[r]) r--;
			if(l>r) continue; 
			ll hash1=0,hash2=0; 
			for(int j=l;j<=r;j++) hash1=hash1*29+s[j]-'a'+1,hash2=hash2*29+t[j]-'a'+1;
			mp[hash1][hash2].pb(i);
			L[i]=l-1,R[i]=len-r;
			for(int j=1;j<l;j++) Hash1[i]=Hash1[i]*29+s[j]-'a'+1;
			for(int j=r+1;j<=len;j++) Hash2[i]=Hash2[i]*29+s[j]-'a'+1;
		} 
		base[0]=1;
		for(int i=1;i<=5000000;i++) base[i]=base[i-1]*29;
		auto HASH=[&](const int &x,const int &len){return hash[x]-hash[x-len]*base[len];}; 
		auto Solve=[&](const vector<int>&v,int len,int l,int r){
			int ans=0;
			for(int i:v) if(L[i]<l&&R[i]<=len-r&&HASH(l-1,L[i])==Hash1[i]&&HASH(r+R[i],R[i])==Hash2[i]) ans++; 
			return ans;
		};
		int l1,l2;
		while(q--){
			scanf("%s%s",s+1,t+1),l1=strlen(s+1),l2=strlen(t+1);
			if(l1!=l2){
				printf("0\n");
				continue;
			}
			int l=1,r=l1;
			while(l<=l1&&s[l]==t[l]) l++;
			while(r>=1&&s[r]==t[r]) r--;
			ll hash1=0,hash2=0; 
			for(int i=l;i<=r;i++) hash1=hash1*29+s[i]-'a'+1,hash2=hash2*29+t[i]-'a'+1;
			for(int i=1;i<=l1;i++) hash[i]=hash[i-1]*29+s[i]-'a'+1;
			printf("%d\n",Solve(mp[hash1][hash2],l1,l,r));
		}
		return 0;
	}
}
int main(){
//	while(1) //100
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	hwq::main();
	return 0;
}
/*
这个电脑卡死了，懒得喷
对于每次询问，问有多少个i满足：s[i][1]=t[l~r][1],s[i][2]=t[l~r][2]且t[1~l-1][1]=t[1~l-1][2],t[r+1~n][1]=t[r+1~n][2]
特判len(t[1])!=len(t[2])
找到t[1~l-1][1]=t[1~l-1][2]的最小l和t[r+1~n][1]=t[r+1~n][2]的最大r 
那么我们替换的区间至少要包含[l,r]，hash快速求解25pts
考虑q=1的情况
好难啊，明年见
len>B，则这样的询问不足B个，用t[l,r][i]去匹配s，具体地，遍历s串的每一位，看其是否合法 
len<B，则B*n的预处理 
？？？范围怎么是5e6？？？炸了，明年见
这题线性做法是何意？
s必为t的子串，恐怖诡异题目 
注意到大样例很小，但其实是因为数据太水了
！！！如果i对j有贡献，则说明si的[l,r]和tj的[l,r]一样！！！
且除去以后，剩下的段相等，但前后1等于2的段怎么处理？
啊啊啊啊好烦啊！！！事已至此，先写伪算，你不仁别怪我不义 
贡献最多为O(n) 
*/
