#include<bits/stdc++.h>
using namespace std;
long long n=0,k=0,ans=0;
long long a[200100]={0},d[200100]={0};
int main(){
    freopen("xor.in",r,stdin);
    freopen("xor.out",w,stdout);
    cin>>n>>k;
    cin>>a[1];
    d[1]=a[1];
    for(int i = 2;i<=n;i++){
        cin>>a[i];
        d[i]=(d[i-1]^a[i]);
    }
    int l=1,r=n+1;
    for(int i = 1;i<=n+1;i++){
        if(i>r&&(d[r]^d[l-1])==k){
            ans++;
            l=i;r=n+1;
        }
        if(i>n)break;
        int g = i,h = i;
        while(h<=n&&(d[h]^d[g-1])!=k){
                h++;
        }
        if(h>n)continue;
        if(r>h){
            l=g;r=h;
        }
    }
    cout<<ans;
    return 0;
}
/*
4 3
2 1 0 3
4 2
2 1 0 3
4 1
2 1 0 3
4 0
2 1 0 3
*/
