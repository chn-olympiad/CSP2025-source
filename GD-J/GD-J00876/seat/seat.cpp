#include<bits/stdc++.h>
using namespace std;
int a[105];
int n,m;
bool cmp(int x,int y){
     return x>y;
}
int find(int x){
    for(int i=1;i<=n*m;i++) if(a[i]==x) return i;
}
int main(){
    freopen("seat.in","r", stdin);
    freopen("seat.out","w", stdout);
    cin >>m >> n;
    for(int i=1;i<=n*m;i++){
    cin >>a[i];
    }
    int x=a[1];
    sort(a+1,a+1+n*m,cmp);
    int pos=find(x);
    int hang,lie;
    lie=(pos+m-1)/m;
    if(lie%m==0) hang=m;
    else if(lie&1) hang=pos%m;
    else hang=m-pos%m+1;
    cout <<lie << ' ' <<hang;
    return 0;
}
