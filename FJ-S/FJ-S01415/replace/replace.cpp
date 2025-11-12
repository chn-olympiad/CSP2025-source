#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 2e5+5; 
const int MAXL = 5e6+5;
const int K = 131;
const long long M = 1e9+7;
int n,q,cnt;
string s[MAXN][2];//s[i][0]表示原字符串,s[i][1]表示最小匹配字符串 
long long sh[MAXN][3],tsh[MAXL],powK[MAXL];//字符串哈希[0]匹配,[1]匹配前,[2]匹配后 
int sz[MAXN][2];//[0]匹配前长度,[2]匹配后长度 
long long GetSh(string& str){
	long long ans = 0;
	for(int i = 0;i<str.size();i++)
		ans = (ans*K+str[i]-'A'+1)%M;
	return ans;
}
long long GetSh(string& str,int l,int r){
	if(l>r)return 0;
	long long ans = 0;
	for(int i = l;i<=r;i++)
		ans = (ans*K+str[i]-'A'+1)%M;
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	powK[0] = 1;
	for(int i = 1;i<MAXL;i++)
		powK[i] = (powK[i-1]*K)%M;
	for(int i = 1;i<=n;i++){
		string s1;
		cnt++;
		cin>>s[cnt][0]>>s1;
		int l = -1,r;
		for(int j = 0;j<s1.length();j++){
			if(s[cnt][0][j] == s1[j])continue;
			if(l == -1)l = j;
			r = j;
		}
		//去除完全相同的替换 
		if(l == -1){
			s[cnt][0].clear();
			cnt--;
			continue;
		}
		//计算最小匹配字符串
		for(int j = l;j<=r;j++){
			s[cnt][1]+=s[cnt][0][j];
			s[cnt][1]+=char(s1[j]-'a'+'A');
		}
		//cout<<s[cnt][1]<<endl;
		sh[cnt][0] = GetSh(s[cnt][1]);
		sh[cnt][1] = GetSh(s[cnt][0],0,l-1);
		sh[cnt][2] = GetSh(s[cnt][0],r+1,s[cnt][0].size()-1);
		sz[cnt][0] = l;
		sz[cnt][1] = s[cnt][0].size()-r-1;
	}
	
	while(q--){
		string t1,t2;
		int ans = 0;
		cin>>t1>>t2;
		if(t1.length()!=t2.length()){
			cout<<0<<endl;
			continue;
		}
		//找到需要替换的最小子串 
		int l = -1,r;
		for(int i = 0;i<t1.length();i++){
			if(t1[i] == t2[i])continue;
			if(l == -1)l = i;
			r = i;
		}
		string ds;
		//计算匹配字符串
		for(int i = l;i<=r;i++){
			ds+=t1[i];
			ds+=char(t2[i]-'a'+'A');
		}
		long long dhs = GetSh(ds);
		
		//计算t1的hash的前缀和数组 
		tsh[0] = (t1[0]-'A'+1)%M;
		for(int i = 1;i<t1.length();i++){
			tsh[i] = (tsh[i-1]*K+t1[i]-'A'+1)%M;
		}
		
		for(int i = 1;i<=cnt;i++){
			if(dhs != sh[i][0])continue;//将si的匹配前部分和匹配后部分 分别同t作比较 
			//大小比较,避免越界 
			if(sz[i][0]>l||sz[i][1]>t1.length()-r||
			(l-sz[i][0] <= 0?tsh[l-1]:(M+tsh[l-1]-tsh[l-sz[i][0]-1]*powK[sz[i][0]]%M)%M)!=sh[i][1]||
			(M+tsh[r+sz[i][1]]-tsh[r]*powK[sz[i][1]]%M)%M!=sh[i][2])continue;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
