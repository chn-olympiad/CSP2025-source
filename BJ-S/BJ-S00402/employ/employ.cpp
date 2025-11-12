#include <bits/stdc++.h>
using namespace std;
const int N=505,P=998244353;
int n,m,ans,cnt,maxi,mini,c[N],p[N];
string s;
inline void file(){freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);}
inline int jc(int k){
    long long res(1);
    for(int i(2);i<=k;++i) (res*=i)%=P;
    return res;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> n >> m >> s;
    for(int i(0);i<n;++i) maxi+=(s[i]=='1');
    for(int i(1);i<=n;++i) cin >> c[i],mini+=(c[i]==0);
    if(maxi<m) return cout << 0,0;
    if(n-mini<m) return cout << 0,0;
    for(int i(1);i<=n;++i) p[i]=i;
    do{
        cnt=0;
        for(int i(1);i<=n;++i) if(cnt>=c[p[i]]||s[i-1]=='0') ++cnt;
        if(n-cnt>=m) ++ans;
    }while(next_permutation(p+1,p+n+1));
    cout << ans;
    return 0;
}
/*
考试差不多该结束了，写点有的没的。
写的很爽啊！感觉区分度比入门组高不少。你这不是会出题吗.jpg
t1是简单的贪心，t2也比较套路，但是有点卡常，希望不要爆零。
t3的话我的做法极其依赖数据强度，属于是比较费力，但是大样例跑得飞快。
今天最大的失策是以为t1是dp，在暴力上还卡了挺久。
上限得分100+100+100+8，下限0+0+0+0（对拍0个题，不过全都通过了大样例），比较有敌，期望154。
求数据把我水进WC线吧/ll
最后一年我真的不要爆零。
有点好奇 dyx 写的咋样，看他一直没上厕所，不符合刻板印象啊。
还很好奇 sdhj，好像哥们就自己一个人在4号楼考试，比较惨。
*/