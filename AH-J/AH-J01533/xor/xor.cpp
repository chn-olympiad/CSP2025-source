#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, k;
const int N=5e5+5;
int a[N]; bool flag, flag2;
int qm[20]={1,2,4,8,16,32,64,128,256};
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++) {
       scanf("%d", &a[i]);
       if(a[i]!=1) flag=1;
       if(a[i]!=1&&a[i]!=0) flag2=1;
    }
    if(flag==0) {
        //only 1
        if(k==0) {cout<<n/2; return 0;}
    } else if(flag2==0) {
        if(k==0) {
            int cnt=0; bool f=0;
            for(int i=1; i<=n; i++) {
                if(a[i]==0) { cnt++; f=0; }
                if(a[i]==1&&f==1) {f=0; cnt++;}
                if(a[i]==1&&f==0) f=1;
            }
            cout<<cnt; return 0;
        } else if(k==1) {
            int cnt=0;
            for(int i=1; i<=n; i++)if(a[i]==1) cnt++;
            cout<<cnt; return 0;
        }
    } else {
        //xor result < 2^
        int ans=0;
        int pos=0; while(qm[pos]<=k) pos++;
        pos-=1;
        for(int i=1; i<=n; i++) if(a[i]>=qm[pos]&&a[i]<qm[pos+1]) ans++;
        cout<<ans;
    }
    return 0;
}
