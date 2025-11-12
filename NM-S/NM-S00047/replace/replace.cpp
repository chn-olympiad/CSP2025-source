#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int n,q,tree[N][30],cnt,fail[N],ans;
string a,flag[N],to[N];
void init(int x){
    for(int i=0;i<26;i++){
        if(tree[x][i]){
            //fail[tree[x][i]]=tree[fail[x]][i];
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        cin>>a;
        int x=0;
        for(int i=0;i<a.size();i++){
            if(tree[x][a[i]-'a']) x=tree[x][a[i]-'a'];
            else x=tree[x][a[i]-'a']=++cnt;
        }
        flag[x]=a;
        cin>>a;
        to[x]=a;
    }
    init(0);
    return 0;
}
