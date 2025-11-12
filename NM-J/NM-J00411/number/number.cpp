#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int num[N];
void merg(int l,int r,int mid){
    int p1=l,p2=mid+1,i=0;
    int help[r-l+1];
    while(p1<=mid&&p2<=r)help[i++]=num[p1]<=num[p2]?num[p2++]:num[p1++];
    while(p1<=mid)help[i++]=num[p1++];
    while(p2<=r)help[i++]=num[p2++];
    for(i=0;i<r-l+1;i++)num[i+l]=help[i];
}
void mergeSort(int l,int r){
    if(l>=r)return;
    int mid=l+((r-l)>>1);
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merg(l,r,mid);
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[j++]=s[i]-'0';
        }
    }
    mergeSort(0,j-1);
    for(int i=0;i<j;i++)cout<<num[i];
}
