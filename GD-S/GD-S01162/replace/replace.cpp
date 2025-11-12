#include<bits/stdc++.h>
#define N 200005
#define L 5000006
using namespace std;
int n,q;
string s[N][3];
string t[N][3];
int tmpa,tmpb;
int bor[L];
int res[N];
void sub1(){
    for(int i=1;i<=n;i++){
        bor[1]=0;
        int l=s[i][1].size();
        for(int j=2;j<=l;j++){
            bor[j]=bor[j-1];
            while(bor[j]&&make_pair(s[i][1][j-1],s[i][2][j-1])!=make_pair(s[i][1][bor[j]],s[i][2][bor[j]])){
                bor[j]=bor[bor[j]];
            }
            if(make_pair(s[i][1][j-1],s[i][2][j-1])==make_pair(s[i][1][bor[j]],s[i][2][bor[j]])){
                bor[j]++;
            }
        }
        for(int j=1;j<=q;j++){
            if(t[j][1].size()!=t[j][2].size())continue;
            int ll=t[j][1].size();
            int cur=0;
            for(int k=1;k<=ll;k++){
                while(bor[j]&&make_pair(t[j][1][k-1],t[j][2][k-1])!=make_pair(s[i][1][cur],s[i][2][cur])){
                    cur=bor[cur];
                }
                if(make_pair(t[j][1][k-1],t[j][2][k-1])==make_pair(s[i][1][cur],s[i][2][cur])){
                    cur++;
                }
                // cerr<<i<<" "<<j<<" "<<k<<" "<<cur<<endl;
                if(cur==l){
                    bool flag=true;
                    for(int p=1;p<=k-l;p++){
                        if(t[j][1][p-1]!=t[j][2][p-1]){
                            flag=false;
                            break;
                        }
                    }
                    for(int p=k+1;p<=ll;p++){
                        if(t[j][1][p-1]!=t[j][2][p-1]){
                            flag=false;
                            break;
                        }
                    }
                    if(flag){
                        res[j]++;
                    }
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",res[i]);
    }
}
map<int,vector<pair<int,int>>>p;
map<int,vector<pair<int,int>>>pp;
void sub2(){
    for(int i=1;i<=n;i++){
        int l=s[i][1].size();
        int a,b;
        for(int j=0;j<l;j++){
            if(s[i][1][j]=='b'){
                a=j;
            }
            if(s[i][2][j]=='b'){
                b=j;
            }
        }
        // cerr<<"a"<<a<<" "<<b<<" "<<l<<endl;
        p[b-a].push_back(make_pair(a,l-b-1));
    }
    for(int i=1;i<=q;i++){
        if(t[i][1].size()!=t[i][2].size()){
            printf("0\n");
            continue;
        }
        int l=s[i][1].size();
        int a,b;
        for(int j=0;j<l;j++){
            if(s[i][1][j]=='b'){
                a=j;
            }
            if(s[i][2][j]=='b'){
                b=j;
            }
        }
        // cerr<<"b"<<a<<" "<<b<<" "<<l<<endl;
        for(auto pq:p[b-a]){
            if(pq.first<=a&&pq.second<=l-b-1){
                res[i]++;
            }
        }
        printf("%d\n",res[i]);
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
        tmpa+=s[i][1].size();
        tmpa+=s[i][2].size();
    }
    for(int i=1;i<=q;i++){
        cin>>t[i][1]>>t[i][2];
        tmpb+=t[i][1].size();
        tmpb+=t[i][2].size();
    }
    if(1ll*tmpb*n<=100000000){
        sub1();
    }else{
        sub2();
    }
}
