#include<bits/stdc++.h>
using namespace std;
const unsigned long long MOD1=1e6+7,MOD2=3797327,res=131,MAXN=1e7+20;int ans;
int n,q;
int hs1_1[MAXN],hs1_2[MAXN],hs2_1[MAXN],hs2_2[MAXN];
string s_1,s_2;

unsigned long long get_hs1(string s){
	unsigned long long a;
	int r=1;
	int len=s.size();
	for(int i=0;i<len;i++){
		a=a+((r*res)%MOD1*s[i]%MOD1)%MOD1;
	}
	return a;
}
unsigned long long get_hs2(string s){
	unsigned long long a;
	int r=1;
	int len=s.size();
	for(int i=0;i<len;i++){
		a=a+((r*res)%MOD2*s[i]%MOD2)%MOD2;
	}
	return a;
}
void dfs(int l,int r,int len,string s,string c){
	if(l<0) return ;
	if(r>=len) return ;	
	int cntt=0,cnttt=0;
	string sa,sb;
	for(int i=l;i<=r;i++){
		sa[cntt]=s[i];
		sb[cnttt]=c[i];
		cntt++;
		cnttt++;
	}
	ans+=hs1_1[get_hs1(sa)];
	dfs(l-1,r,len,s,c);
	dfs(l,r+1,len,s,c);
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s_1>>s_2;
//		hs1_1[get_hs1(s_1)]++;
//		hs1_2[get_hs2(s_1)]++;
//		hs2_1[get_hs1(s_2)]++;
//		hs2_2[get_hs2(s_2)]++;
	}
	for(int i=1;i<=q;i++){
		int f=0;
		int cnt_l,cnt_r;
		cin>>s_1>>s_2;
		int len1=s_1.size();
		for(int j=0;j<len1;j++){
			if(s_1[j]!=s_2[j]&&f==0){
				cnt_l=j;
				f=1;
			}
			if(s_1[j]!=s_2[j]){
				cnt_r=j;
			}
			
		}
		ans=0;
//		dfs(cnt_l,cnt_r,len1,s_1,s_2);
		cout<<ans<<"\n";
	}
	return 0;
}
