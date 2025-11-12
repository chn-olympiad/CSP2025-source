#include<iostream>
using namespace std;
int a[11];
string x;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x;
    int l=x.length();
    for(int i=0;i<l;i++) if(x[i]>='0'&&x[i]<='9') a[x[i]-'0']++;
    for(int i=9;i>=0;i--)
    {
        while(a[i]>0) cout<<i,a[i]--;
    }
    cout<<endl;
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
//13 min 4ge dou guo le,yin gai 100pts
//8:43
