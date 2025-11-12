#include<bits/stdc++.h>
using namespace std;

struct S{
    int a,b,c;
};



int n;
S s[(int)1e5+5];
int book[(int)1e5+5],ans=0;


int check(int x){
    int k=0;
    for(int i=1;i<=x;i++){
        if(book[i]==1)  k+=s[i].a;
        if(book[i]==2)  k+=s[i].b;
        if(book[i]==3)  k+=s[i].c;
    }
    return k;
}


void dfs(int x,int a,int b,int c){
    if(a>n/2||b>n/2||c>n/2) return ;
    if(x>n){
        ans=max(ans,check(x-1));
        return ;
    }
    book[x]=1;
    dfs(x+1,a+1,b,c);
    book[x]=2;
    dfs(x+1,a,b+1,c);
    book[x]=3;
    dfs(x+1,a,b,c+1);
}

void work(){
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>s[i].a>>s[i].b>>s[i].c;
    dfs(1,0,0,0);
    cout<<ans<<endl;
}


int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++) work();
    return 0;
}
