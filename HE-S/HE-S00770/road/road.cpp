#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("roud.in","r",stdin);
    freopen("roud.out","w",stdout);
    int a,b;
    cin>>a;
    for(int i=0;i<=a;i++){
    cin>>b;
    }
    int n[a+1][b+1],maxn[b+1]={},maxm[b+1]={},r[a+1]={},cm=0;
    for(int g=0;g<=b;g++){
            cm=0;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            cin>>n[i][j];
        }
    }
    for(int k=0;k<=b;k++){
        for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                if(n[i][j+1]>maxm[i]){
                maxm[i]=n[i][j];
                }
            }
        }
    r[k]++;
    maxn[k]=maxm[b];
    }
    for(int i=0;i<=b;i++){
        if(r[i]/2>2){
            maxn[i]=maxm[b-1];//ewgfwrgwrrrrrrrrrrrrrrrrrrrrrrggggggg
        }
        cm+=maxn[i];
    }
    cout<<cm;
    }
    return 0;
}

