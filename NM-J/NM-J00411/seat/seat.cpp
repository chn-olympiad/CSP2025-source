#include<bits/stdc++.h>
using namespace std;
const int N=110;
int seat[N],n,m;
void merg(int l,int r,int mid){
    int p1=l,p2=mid+1,i=0;
    int help[r-l+1];
    while(p1<=mid&&p2<=r)help[i++]=seat[p1]<=seat[p2]?seat[p2++]:seat[p1++];
    while(p1<=mid)help[i++]=seat[p1++];
    while(p2<=r)help[i++]=seat[p2++];
    for(i=0;i<r-l+1;i++)seat[i+l]=help[i];
}
int findt(int k){
    int l=0,r=n*m-1;
    while(l<=r){
        int mid=l+((r-l)>>1);
        if(seat[mid]<=k)r=mid-1;
        else l=mid+1;
    }
    return l;
}
void mergeSort(int l,int r){
    if(l>=r)return;
    int mid=l+((r-l)>>1);
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merg(l,r,mid);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>seat[i];
    }
    int now=seat[0];
    //cout<<now<<endl;
    mergeSort(0,n*m-1);
    //for(int i=0;i<n*m;i++)cout<<seat[i]<<" ";
    //cout<<endl;
    now=findt(now);
    int a=(now+1)%n,b=(now+1)/n;
    if(a==0)b--,a=n;
    b++;
    if(b%2==0)a=n-a+1;
    cout<<b<<" "<<a;
}
