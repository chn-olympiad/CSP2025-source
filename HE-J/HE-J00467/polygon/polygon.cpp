#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,stick[5005];



void takeStick(int needEdge,int takeLevel,int totalLength,int lastTakeLength,int beginLoc){
    if(needEdge==takeLevel){
        if(lastTakeLength*2 < totalLength){
            ans++;
        }
            return;
    }
    for(int i=beginLoc+1;i<n;i++){
        if(n-i<needEdge-takeLevel) return;


        takeStick(needEdge,takeLevel+1,totalLength+stick[i],stick[i],i);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stick[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(stick[j]<stick[i]) swap(stick[j],stick[i]);
        }
    }
    //shuruwancheng


    for(int i=3;i<=n;i++){
        takeStick(i,0,0,0,-1);
    }
    cout<<ans;
    return 0;
}
