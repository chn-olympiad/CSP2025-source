#include<iostream>
using namespace std;
int n,k,flag,a[500001],s[500001],f[500001][21],cnt,res;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
    for(int i=1;i<=n;i++)
    {
        res^=a[i];
        if(res==k) res=0,cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
//luogu914813 Undercraft
//acta est fabula,plaudite
//xi wang bu yao AFO
//shun bian ji lian yong yuan de vivid/stasis
//hao xiang 2026nian jiu ting gen le
//csp-j JS-J00493 csp-s JS-S00500
//chu sai -j 98 -s 72
//di 3 nian le
//ming tian gai si de dong tai shi shi yan zhong xue jiu yao yue kao
//tmd,zhe xiang dang yu cspj-s day 2
//csp-j 2025
//10:19 xiang bu chu lai le
//xian zhe yang ba 10~20pts
