#include<bits/stdc++.h>
using namespace std;
#define sp putchar(' ')
#define el putchar('\n')
using ll=__int128;
inline ll read(){
    ll x=0;
    int f=1;
    char cc=getchar();
    while(!isdigit(cc)){
        if(cc=='-'){
            f=-f;
        }
        cc=getchar();
    }
    do{
        x=(x<<1)+(x<<3)+(cc^'0');
    }while(isdigit(cc=getchar()));
    return f*x;
}
inline void print(ll x){
    if(x<0){
        putchar('-');
        print(-x);
    }else if(x<10){
        putchar(x^'0');
    }else{
        print(x/10);
        putchar(x%10^'0');
    }
}
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    vector<int>a;
    for(char c:s){
        if(isdigit(c)){
            a.push_back(c^'0');
        }
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int x:a){
        print(x);
    }
    el;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
