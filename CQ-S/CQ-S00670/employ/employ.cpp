#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,c[20],dp[20][282144],ans;
string s;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n>18){
		cout<<"0\n";
		return 0; 
	}
	for(int i=0;i<n;i++)cin>>c[i];
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int ppc=0;
		for(int j=0;j<n;j++)if((i>>j)&1)ppc++;
		for(int j=0;j<=ppc;j++){
//			cerr<<i<<' '<<j<<' '<<dp[j][i]<<'\n';
			for(int k=0;k<n;k++)if(!((i>>k)&1)){
				int add=(s[ppc]=='1'&&c[k]>(ppc-j));
				dp[j+add][i|(1<<k)]=(dp[j+add][i|(1<<k)]+dp[j][i])%p;
			}
		} 
	}

	for(int j=m;j<=n;j++){
		ans=(ans+dp[j][(1<<n)-1])%p; 
	} 
	cout<<ans;









	return 0;
}
/*
给定一个前缀和，前缀和要么+0要么+1

给数列重新排列，求使得 cnt of ai>qzhi 至少是m的方案数 

显然有一个 状态压缩的做法

已经有.不.少.于ci人被拒绝或放弃参加面试，则他也将放弃参加面试。

所以前面jio了也会计入

12~15 分别对应每个数只能放前缀/后缀

这不就是 A 性质？？ 

不是。

 

freeopen froopen froepen 

club.exe < club1.in > club1.out
fc club1.out club1.ans
club.exe < club2.in > club2.out
fc club2.out club2.ans
club.exe < club3.in > club3.out
fc club3.out club3.ans
club.exe < club4.in > club4.out
fc club4.out club4.ans
club.exe < club5.in > club5.out
fc club5.out club5.ans

road.exe < road1.in > road1.out
fc road1.out road1.ans
road.exe < road2.in > road2.out
fc road2.out road2.ans
road.exe < road3.in > road3.out
fc road3.out road3.ans
road.exe < road4.in > road4.out
fc road4.out road4.ans

replace.exe < replace1.in > replace1.out
fc replace1.out replace1.ans
replace.exe < replace2.in > replace2.out
fc replace2.out replace2.ans
replace.exe < replace3.in > replace3.out
fc replace3.out replace3.ans
replace.exe < replace4.in > replace4.out
fc replace4.out replace4.ans

employ.exe < employ1.in > employ1.out
fc employ1.out employ1.ans
employ.exe < employ2.in > employ2.out
fc employ2.out employ2.ans
employ.exe < employ3.in > employ3.out
fc employ3.out employ3.ans
employ.exe < employ4.in > employ4.out
fc employ4.out employ4.ans
employ.exe < employ5.in > employ5.out
fc employ5.out employ5.ans

我没时间整活了，如果想看整活请到 CQ-J00654

luogu：1096384 ctzm 








*/


