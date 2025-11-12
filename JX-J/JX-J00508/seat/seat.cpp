#include<bits/stdc++.h>
using namespace std;
const int maxn=1000101;
int n,m,x,p,s[maxn];
bool sm(int g,int h){
    return g>h;
}
void xb(int a[]){
    for(int i=1;i<=p;i++){
        int x=a[i];
        for(int j=i;j<=p;j++){
            if(a[j]>a[i]){
                swap(a[j],a[i]);
                swap(s[i],s[j]);
            }
        }
    }
}
struct px{
    int xb;
    int cj;
}px[100010];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s[n*m],a[n*m];
    p=n*m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++){
        s[i]=i;
    }
    xb(a);
    for(int i=1;i<=n*m;i++){
        cout<<s[i];
    }
    cout<<1<<2;

    return 0;
}
