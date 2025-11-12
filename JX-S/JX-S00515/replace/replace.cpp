#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2e5+5;
int n,q,poss[N][2],post[N][2],lens[N][2],lent[N][2];
string s[N][2],t[N][2];
// int check(string s1,string s2,string t1,string t2){
//     int n=t1.size(),m=s1.size(),res=0;
//     vector<int>tag1(n),tag2(n);
//     for(int i=0,fl=1;i<n;++i){
//         tag1[i]=(fl&=(t1[i]==t2[i]));
//     }
//     for(int i=n-1,fl=1;i>=0;--i){
//         tag2[i]=(fl&=(t1[i]==t2[i]));
//     }
//     for(int i=0;i+m-1<n;++i){
//         if(t1.substr(i,m)==s1&&t2.substr(i,m)==s2&&(i==0||tag1[i-1])&&(i==n-m||tag2[i+m]))
//             res++;
//         // cout<<i<<' ';
//     }
//     return res;
// }
// vector<int> kmp(string s,string t){
//     vector<int>res(s.size());
//     for(int i=0;i<s.size();++i){
//         if(s.substr(i,t.size())==t)
//             res[i]=1;
//         else
//             res[i]=0;
//     }
//     return res;
// }
int get_pos(string s){
    int len=s.size();
    for(int i=0;i<len;++i){
        if(s[i]=='b')
            return i;
    }
    return 0;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>s[i][1]>>s[i][2];
        poss[i][1]=get_pos(s[i][1]);
        poss[i][2]=get_pos(s[i][2]);
        lens[i][1]=s[i][1].size();
        lens[i][2]=s[i][2].size();
    }
    for(int i=1;i<=q;++i){
        int res=0;
        cin>>t[i][1]>>t[i][2];
        post[i][1]=get_pos(t[i][1]);
        post[i][2]=get_pos(t[i][2]);
        lent[i][1]=t[i][1].size();
        lent[i][2]=t[i][2].size();
        // cout<<post[i][1]<<' '<<post[i][2]<<' '<<lent[i][1]<<' '<<lent[i][2]<<endl;
        if(t[i][1].size()!=t[i][2].size()){
            cout<<0<<'\n';
            continue;
        }
        for(int j=1;j<=n;++j){
            if(poss[j][1] <= post[i][1] && lens[j][1]-poss[j][1] <= lent[i][1]-post[i][1] && post[i][1] - poss[j][1] + poss[j][2] == post[i][2])
                res++;
            // cout<<poss[j][1]<<' '<<post[i][1]<<" | ";
        }
        cout<<res<<'\n';
    }
    return 0;
}
// g++ /home/noi/Desktop/TTY/replace.cpp -o replace -std=c++14 -static

/*
finished egg!
*/