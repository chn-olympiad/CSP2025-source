#include <bits/stdc++.h>
using namespace std;

namespace Cherry {
	const int N=5e6+10;
	const long long base=131;
	const long long mod=123456791;
	int n,q,num,cnt;
	char s1[N],s2[N];
	int tot[N],tot1[27][N],tot2[N][27];
	long long Hs[N],fac[N];
	map<long long,int> app,pir[N];
	
	struct stu {
		int l,r,len;
		long long hs;
	};
	bool cmp(stu a,stu b) { return a.len<b.len; }
	vector<stu> in[N];
	
	long long get(int len,int l,int r) {
		if(l<1||r>len) return 0;
		return (Hs[r]-Hs[l-1]*fac[r-l+1]%mod+mod)%mod;
	}
	
	int main() {
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++) {
			scanf("%s",s1+1);
			scanf("%s",s2+1);
			int len=strlen(s1+1),he=0,en=len+1;
			while(he<len&&s1[he+1]==s2[he+1]) he++;
			while(en>1&&s1[en-1]==s2[en-1]) en--;
			if(he==len) continue; //s1==s2
			long long hs=0;
			for(int i=1;i<=len;i++) hs=(hs*base%mod+s1[i]-'a'+1)%mod;
			long long hs1=0,hs2=0;
			for(int i=he+1;i<=en-1;i++) {
				hs1=(hs1*base%mod+s1[i]-'a'+1)%mod;
				hs2=(hs2*base%mod+s2[i]-'a'+1)%mod;
			}
			if(!app[hs1]) app[hs1]=++num;
			int id=app[hs1];
			if(!pir[id][hs2]) pir[id][hs2]=++cnt;
			int nm=pir[id][hs2];
			if(!he&&en==len+1) tot[nm]++;
			else if(he==1&&en==len+1) tot1[s1[1]-'a'][nm]++;
			else if(!he&&en==len) tot2[nm][s1[len]-'a']++;
			else in[nm].push_back(stu{he,len-en+1,len,hs});
		}
		for(int i=1;i<=cnt;i++) sort(in[i].begin(),in[i].end(),cmp);
		fac[0]=1;
		for(int i=1;i<=5e6;i++) fac[i]=fac[i-1]*base%mod;
		while(q--) {
			scanf("%s",s1+1);
			scanf("%s",s2+1);
			int len=strlen(s1+1),he=0,en=len+1;
			while(he<len&&s1[he+1]==s2[he+1]) he++;
			while(en>1&&s1[en-1]==s2[en-1]) en--;
			for(int i=1;i<=len;i++) Hs[i]=(Hs[i-1]*base%mod+s1[i]-'a'+1)%mod;
			long long hs1=0,hs2=0;
			for(int i=he+1;i<=en-1;i++) {
				hs1=(hs1*base%mod+s1[i]-'a'+1)%mod;
				hs2=(hs2*base%mod+s2[i]-'a'+1)%mod;
			}
			int id=pir[app[hs1]][hs2],ans=tot[id];
			if(he) ans+=tot1[s1[he]-'a'][id];
			if(en<=len) ans+=tot2[id][s1[en]-'a'];
			for(auto x:in[id]) {
				if(x.len>len) break;
				if(x.hs==get(len,he-x.l+1,en+x.r-1)) ans++;
			}
			printf("%d\n",ans);
		}

		return 0;
	}
}

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Cherry::main();
//	内存:449MB 

	return 0;
}
/*
合法状况不是很好构造
答案肯定很小
数据大概率也就会很水吧
有点怕被卡自然溢出 

emmm 但是大样例有点太水了啊 
*/
