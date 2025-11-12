#include<bits/stdc++.h>
using namespace std;
int a[100090],b[10000],c[10000],pis[10000],ans;
int n;
struct club{
    int d,e,r;
};
int maxn(int a,int b,int c){
    int p=max(a,b);
    return max(p,c);
}
bool cmp(int x,int y){
return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i]>>b[i]>>c[i];
    }
    club number;
    number.d=n/2,number.e=n/2,number.r=n/2;
    sort(a,a+n,cmp);
    for(int i=n;i>=n/2;++i)
    ans+=i;
    cout<<ans;
}
return 0;
}
