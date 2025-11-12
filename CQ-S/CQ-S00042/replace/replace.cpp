#include <bits/stdc++.h>
using namespace std;
namespace yhy{
    #define int long long
    const int p1=101,Mod1=998244353;
    const int p2=103,Mod2=1e9+7;
    struct node{
        int len;
        int l,r;
        int val1,val2;
        int change1,change2;
    }a[200005];
    int n,q;
    string s1,s2;
    map<pair<int,int>,int> mp;
    int tot_mp;
    vector<int> vt[200005];
    int b[5000005];
    int c[5000005];
    int pow_1[5000005];
    int pow_2[5000005];
	int main() {
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		std::ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
        cin>>n>>q;
        pow_1[0]=pow_2[0]=1;
        for(int i=1;i<=5000000;i++) {
            pow_1[i]=pow_1[i-1]*p1%Mod1;
            pow_2[i]=pow_2[i-1]*p2%Mod2;
        }
        for(int i=1;i<=n;i++) {
            cin>>s1>>s2;
            // if(i==24765) {
            //     cout<<s1<<" "<<s2<<'\n';
            // }
            int m=s1.size();
            a[i].len=m;
            s1=" "+s1;
            s2=" "+s2;
            // cout<<"i:"<<i<<'\n';
            for(int j=1;j<=m;j++) {
                a[i].val1=(a[i].val1*p1+s1[j]-'a')%Mod1;
                a[i].val2=(a[i].val2*p2+s2[j]-'a')%Mod2;
                // cout<<"j:"<<j<<" a[i].val1:"<<a[i].val1<<" a[i].val2:"<<a[i].val2<<'\n';
                if(s1[j]!=s2[j]) {
                    if(!a[i].l) {
                        a[i].l=j;
                    }
                    a[i].r=j;
                }
            }
            if(!a[i].l) {
                continue;
            }
            for(int j=a[i].l;j<=a[i].r;j++) {
                a[i].change1=(a[i].change1*p1+s1[j]-'a')%Mod1;
                a[i].change2=(a[i].change2*p2+s2[j]-'a')%Mod2;
                // cout<<"change1:"<<a[i].change1<<" change2:"<<a[i].change2<<'\n';
            }
            // cout<<a[i].change1<<" "<<a[i].change2<<'\n';
            if(!mp[{a[i].change1,a[i].change2}]) {
                mp[{a[i].change1,a[i].change2}]=++tot_mp;
            }
            // cout<<"mp:"<<mp[{a[i].change1,a[i].change2}]<<" id:"<<i<<'\n';
            vt[mp[{a[i].change1,a[i].change2}]].push_back(i);
            // cout<<"a[i].l:"<<a[i].l<<" a[i].r:"<<a[i].r<<"\n";
        }
        for(int i=1;i<=q;i++) {
            cin>>s1>>s2;
            int m=s1.size();
            s1=" "+s1;
            s2=" "+s2;
            int fst=0,lst=0;
             for(int j=1;j<=m;j++) {
                b[j]=(b[j-1]*p1+s1[j]-'a')%Mod1;
                c[j]=(c[j-1]*p2+s2[j]-'a')%Mod2;
                if(s1[j]!=s2[j]) {
                    if(!fst) {
                        fst=j;
                    }
                    lst=j;
                }
            }
            int def1=0,def2=0;
            for(int j=fst;j<=lst;j++) {
                def1=(def1*p1+s1[j]-'a')%Mod1;
                def2=(def2*p2+s2[j]-'a')%Mod2;
            }
            // cout<<"def1:"<<def1<<" def2:"<<def2<<'\n';
            int x=mp[{def1,def2}];
            if(!x) {
                cout<<0<<'\n';
                continue;
            }
            // cout<<"i:"<<i<<" Pass\n";
            int ans=0;
            for(auto v:vt[x]) {
                // cout<<"v:"<<v<<'\n';
                int left=fst-a[v].l+1;
                int right=left+a[v].len-1;
                // cout<<"left:"<<left<<" right:"<<right<<'\n';
                if(left<1 || right>m) continue;
                // cout<<"b[right]:"<<b[right]<<" b[left-1]:"<<b[left-1]<<" pow_1[left-1]:"<<pow_1[left-1]<<'\n';
                int now1=(b[right]-b[left-1]*pow_1[a[v].len]%Mod1+Mod1)%Mod1;
                // cout<<"now1:"<<now1<<" val1:"<<a[v].val1<<'\n';
                if(now1!=a[v].val1) continue;
                int now2=(c[right]-c[left-1]*pow_2[a[v].len]%Mod2+Mod2)%Mod2;
                // cout<<"now2:"<<now2<<" val2:"<<a[v].val2<<'\n';
                if(now2!=a[v].val2) continue;
                // if(i==569) {
                //     cout<<s1<<" "<<s2<<'\n';
                //     cout<<"v:"<<v<<'\n';
                // }
                ans++;
            }
            cout<<ans<<'\n';
        }
		return 0;
	}
}
signed main() {
	yhy::main();
	return 0;
}
/*
怎么是串串题

完全没复习字符串知识啊

先开 T4 去了

这个的限制条件还是没星战严格的，不可以总司令感觉得分不会很高

15：32 先开 T4 吧

15:39 T4 完全没思路，滚回来了

疑似有个思路

把 AC 自动机建出来

abcd -> abca

那么 d-> a 的方案数++

感觉这个思路很对啊

但问题是万一替换的太短了呢

已经思考 1h+ 了

暂时的思路是直接哈希

哎还是这么弄吧

期望得分:30 pts

没事没事

不会做没关系

好好打暴力

尽力而为

哎

OI 就是这样的

即使这道题目只有 2100

我不会做，它对我而言就是 3500

自信打暴力吧

不管其他的了

晚上回家放声大哭一把然后好好玩

不急，还有 1h

暴力打出来了

我已尽力

哈希冲突了我是真没想到的
*/