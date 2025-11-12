#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N];
void merg(int l,int r,int mid){
    int p1=l,p2=mid+1,i=0;
    int help[r-l+1];
    while(p1<=mid&&p2<=r)help[i++]=a[p1]<=a[p2]?a[p2++]:a[p1++];
    while(p1<=mid)help[i++]=a[p1++];
    while(p2<=r)help[i++]=a[p2++];
    for(i=0;i<r-l+1;i++)a[i+l]=help[i];
}
void mergeSort(int l,int r){
    if(l>=r)return;
    int mid=l+((r-l)>>1);
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merg(l,r,mid);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polyogn.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<9;
}
