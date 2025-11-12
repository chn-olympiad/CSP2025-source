#include <bits/stdc++.h>
using namespace std;
int mid(int a,int b,int c){
    int f=max(max(a,b),c);
    int l=min(min(a,b),c);
    if (a!=b&&a!=c){
        return a;
    }
    else if (b!=a&&b!=c){
        return b;
    }
    else{
        return c;
    }
}
int as(int a,int b,int c,int d){
    if (a==b){
        return 0;
    }
    else if (a==c){
        return 1;
    }
    else{
        return 2;
    }
}
int main(){
    freopen()
    int t;
    cin>>t;
    vector<int> ans(t);
    for(int i=0;i<t;i++){
        int n,cnt[3]={0,0,0},ans;
        vector<int> a(n),b(n),c(n),f(n),m(n),l[n];
        cin>>n;
        for (int j=0;j<n;j++){
            cin>>a[j]>>b[j]>>c[j];
            f[i]=max(max(a[j],b[j]),c[j]);
            l[i]=min(min(int(a[j]),int(b[j])),int(c[j]));
            m[i]=mid(a[j],b[j],c[j]);
            cnt[as(f[j],a[j],b[j],c[j])]++;
            ans[i]+=f[j];
        }
    }
    for (int i=0;i<t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
