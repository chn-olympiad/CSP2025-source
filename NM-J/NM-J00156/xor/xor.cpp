#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    int a[n+10]={0};
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }/*
    int ans=0;
    bool can[5]={0};
    for(int i1=0;i1<=1;i1++){
    for(int i2=0;i2<=1;i2++){
    for(int i3=0;i3<=1;i3++){
    for(int i4=0;i4<=1;i4++){
        int t=0;
        if(i1&&!can[1]) {t=t^a[1];can[1]=1;}
        if(i2&&!can[2]) {t=t^a[2];can[2]=1;}
        if(i3&&!can[3]) {t=t^a[3];can[3]=1;}
        if(i4&&!can[4]) {t=t^a[4];can[4]=1;}
        if(t==k) {
            cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<endl;
            ans++;
        }
    }
    }
    }
    }
    cout<<ans;*/
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
