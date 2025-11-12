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
int main(){
    fastrd
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int>v;
    for(auto i:s){
        if(isdigit(i)){
            v.push_back(i-'0');
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(auto i:v){
        cout<<i;
    }
    return 0;
}
