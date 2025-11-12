#include<bits/stdc++.h>
using namespace std;
const int N=100009;
string S1[N],S2[N],Q1[N],Q2[N];
struct node{int a,b;}Sl[N],Sr[N],Ql[N],Qr[N];
int n,q;
bool ok(string s,int &a,int &b){
    a=b=0;
    int cnt=0;
    for(char c:s){
        if(c=='a'){
            if(cnt==0) ++a;
            else ++b;
        }else if(c=='b'){
            if(cnt==1) return 0;
            else cnt=1;
        }else return 0;
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q; bool B=1;
    for(int i=1;i<=n;i++) cin>>S1[i]>>S2[i];
    for(int i=1;i<=q;i++) cin>>Q1[i]>>Q2[i];
    for(int i=1;i<=n;i++){
        B&=ok(S1[i],Sl[i].a,Sl[i].b);
        B&=ok(S2[i],Sr[i].a,Sr[i].b);
    }
    for(int i=1;i<=q;i++){
        B&=ok(Q1[i],Ql[i].a,Ql[i].b);
        B&=ok(Q2[i],Qr[i].a,Qr[i].b);
    }
    if(B){
        for(int i=1,tmp=0;i<=q;i++){
            tmp=0;
            if(Ql[i].a+Ql[i].b!=Qr[i].a+Qr[i].b) puts("0");
            else for(int j=1;j<=n;j++) if(Sl[j].a-Sr[j].a==Ql[i].a-Qr[i].a&&Sl[j].a<=Ql[i].a&&Sl[j].b<=Ql[i].b) ++tmp;
            printf("%d\n",tmp);
        }
    }
    return 0;
}
/*
g++ -Wall -std=c++14 -O2 -fsanitize=address,undefined replace.cpp -o replace;./replace
5 2
aaaaaaab baaaaaaa
ab ba
aba baa
ba ab
aba aab
aaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaa
aaaaaaab
baaaaaaa
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/