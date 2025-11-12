#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INT __int128
#define u_mp unordered_map
#define u_st unordered_set
#define fastrd ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
template<class T>
T read(){
    char c=getchar();
    T a=0;
    bool f=0;
    while(!isdigit(c)){
        if(c=='-'){
            f=1;
        }
        c=getchar();
    }
    while(isdigit(c)){
        a=a*10+(c-'0');
        c=getchar();
    }
    if(f){
        a=-a;
    }
    return a;
}
template<class T>
void print(T a){
    if(a<0){
        putchar('-');
        a=-a;
    }
    if(a<9){
        putchar(char(a+'0'));
        return;
    }
    print(a/10);
    putchar(char(a%10+'0'));
}
int ans=0,n;
int a[10000];
void dfs(int st,int sum,int maxs,int num){
    if(st==n+1){
        if(num<3){
            return;
        }
        if(sum>maxs*2){
            ans++;
            ans%=998244353;
        }
        return;
    }
    dfs(st+1,sum+a[st],max(maxs,a[st]),num+1);
    dfs(st+1,sum,maxs,num);
    return;
}
int main(){
    fastrd
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        int mx=max(a,max(b,c));
        if(a+b+c>mx*2){
            cout<<1;
        }else{
            cout<<0;
        }
    }else if(n<=20){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1,0,0,0);
        cout<<ans;
    }else{
        cout<<0;
    }

    return 0;
}
