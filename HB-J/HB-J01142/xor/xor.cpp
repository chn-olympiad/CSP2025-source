#include<bits/stdc++.h>
using namespace std;
int n[100002];
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
long long int n1,k,mxor,num;
mxor=0,num=0;
cin>>n1>>k;
int l,r;
l=1,r=1;
for(int i=1;i<=n1;i++)
    cin>>n[i];
while(!(l==r&&r==n1)){
    mxor=n[l];
    if(l!=r)
    for(int i=l+1;i<=r;i++){
        mxor^=n[i];
    }
    if(mxor>k)
        if(r==l)l++,r++;
        else l++;
    else if(mxor<k&&r<n1)r++;
    else{num++;
    if(r==l)l++,r++;else l=r;
}
}
cout<<num;
return 0;
}
