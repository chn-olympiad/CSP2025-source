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
int a[1000000];
int st[100][100];
int n,m;
int b;
int main(){
    fastrd
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];
    int idx=0;
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            idx++;
            if(i%2){
                st[j][i]=a[idx];
                if(a[idx]==b){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }else{
                st[n-j+1][i]=a[idx];
                if(a[idx]==b){
                    cout<<i<<' '<<n-j+1;
                    return 0;
                }
            }
        }
    }
    return 0;
}
