#include<bits/stdc++.h>
using namespace std;
int n,t;
int club1,club2,club3;
struct cmp{
    int a;
    int b;
    int c;
    bool f;
}temp[100010];
bool f1(cmp x,cmp y){
    return x.a>y.a;
}
bool f2(cmp x,cmp y){
    return x.b>y.b;
}
bool f3(cmp x,cmp y){
    return x.c>y.c;
}
int dfs1(int number,int i){
    if(number==n/2||i==n){
        return club1;
    }
    if(temp[i].a>temp[i].b&&temp[i].a>temp[i].c&&temp[i].f!=1){
        club1+=temp[i].a;
        temp[i].f=1;
        number+1;
    }
    else{
        dfs1(number,i+1);
        return club1;
    }
    dfs1(number,i+1);
    return club1;
}
int dfs2(int number,int i){
    if(number==n/2||i==n){
        return club2;
    }
    if(temp[i].b>temp[i].a&&temp[i].b>temp[i].c&&temp[i].f!=1){
        club2+=temp[i].b;
        temp[i].f=1;
        number+1;
    }
    else{
        dfs2(number,i+1);
        return club2;
    }
    dfs2(number,i+1);
    return club2;
}
int dfs3(int number,int i){
    if(number==n/2||i==n){
        return club3;
    }
    if(temp[i].c>temp[i].a&&temp[i].c>temp[i].b&&temp[i].f!=1){
        club3+=temp[i].c;
        temp[i].f=1;
        number+1;
    }
    else{
        dfs3(number,i+1);
        return club3;
    }
    dfs3(number,i+1);
    return club3;
}
int main(){
    freopen("club.in","r",std);
    freopen("club.out","w",std);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>temp[i].a>>temp[i].b>>temp[i].c;
            temp[i].f=0;
        }
        sort(temp+1,temp+1+n,f1);
        dfs1(0,1);
        sort(temp+1,temp+1+n,f2);
        dfs2(0,1);
        sort(temp+1,temp+1+n,f3);
        dfs3(0,1);
        cout<<club1+club2+club3<<endl;
        club1=0;
        club2=0;
        club3=0;
    }
    return 0;
}
