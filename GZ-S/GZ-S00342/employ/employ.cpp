//GZ-S00342 贵阳市第三实验中学 王钦澄
#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],b;
string s;
int f(int a,int r){
    int g=0;
    if(a==n+1)return 0;
    if(r==n+1)return 0;
    for(int i=0;i<n;i++){
        g=g+f(a,r+i)
    }
    if(g>=m){
        b++;
    }
    f(a+1,r);
}
int main(){
    freopen("employ.in",r,stdin);
    freopen("employ.out",w,stdout);
    cin >> n >> m;
    cin >> s;
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    f(1,1);
    cout << b;
    return 0;
}
