#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
bool o[1000005];
int yh(int x,int y){
    int num=0,k=1;
    while(x>0||y>0){
        if(x%2!=y%2){
            num+=k;
        }
        x/=2;
        y/=2;
        k*=2;
    }
    return num;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    for(int i=1;i<=x;i++){
        b[i]=max(b[i],b[i-1]);
        if(o[i]){
            continue;
        }
        if(a[i]==y){
            b[i]++;
            continue;
        }
        for(int j=i+1;j<=x;j++){
            a[i]=yh(a[i],a[j]);
            if(a[i]==y){
                b[j]=max(b[j],b[i]+1);
                o[j]=1;
                break;
            }
        }
    }
    cout<<b[x];
}
