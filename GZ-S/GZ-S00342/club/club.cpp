//GZ-S00342 贵阳市第三实验中学 王钦澄
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005];
int s(int n,int d,int e,int f){
    if(n==0){
        return 0;
    }
    int g=0;
    if(d<=n/2)g=max(g,a[n]+s(n-1,d+1,e,f));
    if(e<=n/2)g=max(g,b[n]+s(n-1,d,e+1,f));
    if(f<=n/2)g=max(g,c[n]+s(n-1,d,e,f+1));
    return g;
}
int main(){
    freopen("club.in",r,stdin);
    freopen("club.out",w,stdout);
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        for(int j=0;j<n;j++){
            cin >> a[j] >> b[j] >> c[j];
        }
        cout << s(n,0,0,0);
    }
    return 0;
}
