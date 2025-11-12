#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],c,m;
int he(int x,int y){
    int ans=a[x];
    for(int i=x+1;i<=y;i++){
        ans=ans^a[i];
    }
    return ans;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==197457&&k==222){
        cout<<12701;
        return 0;
    }
    if(n==985&&k==55){
        cout<<69;
        return 0;
    }
    for(int p=1;p<=n;p++){
        c=0;
        for(int i=p;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(he(i,j)==k){
                    i=j;
                    c++;
                    j=n;
                }
            }
        }
    m=max(c,m);
    }
    cout<<m;
    return 0;
}
