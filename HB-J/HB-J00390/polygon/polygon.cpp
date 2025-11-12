#include<bits/stdc++.h>
using namespace std;
int n,a[5500],f[9999],s,x,y,z,cnt,maxn;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
    }
    if(n==3&&a[1]+a[2]+a[3]>2*maxn){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            f[i]=0;
        x=a[i];
        f[i]=1;
        for(int j=1;j<=n;j++){
            if(f[j]==1)
                continue;
            y=a[j];
            f[j]=1;
            for(int k=1;k<=n;k++){
                if(f[k]==1)
                    continue;
                z=a[k];
            }
        }
        s=x+y+z;
        if(s>2*maxn){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
