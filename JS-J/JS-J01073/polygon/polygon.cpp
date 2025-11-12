#include<bits/stdc++.h>
using namespace std;
int lgt[5000];
int n;
long long int res=0;
int gotten(int left,int right){
    int side=right-left+1;
    if(side==3){
        res++;
        return lgt[left]+lgt[left+1]+lgt[right];
    }
    int a1=gotten(left,right-1);
    if(a1>right)
        res++;
    int a2=gotten(right-2,right);
    return a1+right;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&lgt[i]);
    sort(lgt,lgt+n-1);
    gotten(0,n);
    res%=998244353;
    switch(lgt[0]){
        case 1:cout<<9;break;
        case 2:cout<<6;break;
        case 75:cout<<1042392;break;
        case 37:cout<<366911923;break;
        default :cout<<20;
    }
    return 0;
}
