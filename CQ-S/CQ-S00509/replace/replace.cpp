#include<bits/stdc++.h>
#define int long long
using namespace std;
const int hs=7,mod=1e9+7;
string s[200005][2];
int sum,l[200005][2];
int num[200005][2],pw[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;cin>>n>>q;pw[0]=1;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		l[i][0]=s[i][0][0]-'a',l[i][1]=s[i][1][0]-'a';
		for(int j=1;j<s[i][0].size();j++){
			l[i][0]=(l[i][0]*hs+s[i][0][j]-'a')%mod;
			l[i][1]=(l[i][1]*hs+s[i][1][j]-'a')%mod;
		}
		pw[i]=(pw[i-1]*hs)%mod;
	}
	if(n<=1000&&q<=1000){
		while(q--){int ans=0;
			string t,t1;cin>>t>>t1;
			if(t.size()!=t1.size()){cout<<0<<'\n';continue;}
			num[0][0]=t[0]-'a';num[0][1]=t1[0]-'a';
			for(int i=1;i<t.size();i++){
				num[i][0]=(num[i-1][0]*hs+t[i]-'a')%mod;
				num[i][1]=(num[i-1][1]*hs+t1[i]-'a')%mod;
			}
			int len1=t.size();
			for(int i=1;i<=n;i++){
				int len=s[i][0].size();
				for(int j=0;j<t.size();j++){
					if(j+len-1>=len1) break;
					int sum1=num[j+len-1][0];
					if(j){sum1=(sum1-num[j-1][0]*pw[len]%mod+mod)%mod;}
					if(l[i][0]==sum1){
						int pd=0;
						if(j&&num[j-1][0]!=num[j-1][1]) pd=1;
						if(j!=len1-1&&(num[len1-1][0]-num[j+len-1][0]*pw[len1-1-j-len+1]%mod+mod)%mod!=(num[len1-1][1]-num[j+len-1][1]*pw[len1-1-j-len+1]%mod+mod)%mod) pd=1;
						sum1=num[j+len-1][1];
						if(j){sum1=(sum1-num[j-1][1]*pw[len]%mod+mod)%mod;}
						if(sum1!=l[i][1]) pd=1;
						if(pd==0) ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	return 0;
}
/*
心态爆炸，不会连去年的成绩都达不到吧……
看看这道题，替换操作只能够进行一次
并且如果s中的前面与后面相同的部分可以直接省去，没有必要
还是不会做，只剩50分钟了，现在手中只有200分
完蛋了，今年直接被T2创飞了……
又没有一等奖了……
打满暴力有50分，至少比去年高……
只剩下18分钟了，现在手中仅仅只有225分，被创飞了…… 
*/
