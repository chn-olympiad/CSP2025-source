#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=50010;
int n,k,s[N];
PII xy[N];
void merg(int l,int r,int mid){
    int p1=l,p2=mid+1,i=0;
    PII help[r-l+1];
    while(p1<=mid&&p2<=r)help[i++]=xy[p1].second<=xy[p2].second?xy[p1++]:xy[p2++];
    while(p1<=mid)help[i++]=xy[p1++];
    while(p2<=r)help[i++]=xy[p2++];
    for(i=0;i<r-l+1;i++)xy[i+l]=help[i];
}
void mergeSort(int l,int r){
    if(l>=r)return;
    int mid=l+((r-l)>>1);
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merg(l,r,mid);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s[i]=s[i-1]^x;
        //cout<<s[i]<<" ";
    }
    //cout<<endl;
    int x=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int sd=s[j]^s[i-1];
            if(sd==k){
                xy[x].first=i,xy[x++].second=j;
                //cout<<sd<<" "<<i<<" "<<j<<endl;
            }
        }
    }
    mergeSort(0,x-1);
    int lans=0;
    for(int i=0;i<x;i++){
        int ans=0;
        for(int j=i;j<x;j++){
            if(xy[i].second<xy[j].first) ans++;
            //cout<<xy[i].second<<" "<<xy[j].first<<endl;
        }
        lans=max(lans,ans);
    }
    cout<<lans;
}
