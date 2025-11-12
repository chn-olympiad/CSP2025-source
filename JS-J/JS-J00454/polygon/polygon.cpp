#include<bits/stdc++.h>
using namespace std;
int n,num[5005],ans[5005],maxn;
bool num1[5005];
long long add,anss;

bool cmp(int a,int b){
    return a>b;
}
void tmp(int m,int x,int l){
    if(x>m){
       for(int i=1;i<x;i++){
           maxn=max(maxn,ans[i]);
           add+=ans[i];
       }
       int mm=2*maxn;
       if(add > mm){
            anss++;
            anss=anss%998244353;
       }
       add=maxn=0;
    }
    else{
        for(int i=l;i<=n;i++){
            if(x==1){
                if(m+i-1>n){
                    i=n+1;
                    break;
                }
            }
            if(num1[i]==0){
                num1[i]=1;
                ans[x]=num[i];
                tmp(m,x+1,i+1);
                num1[i]=0;
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num,num+1,cmp);
    for(int i=3;i<=n;i++){
        ans[1]=-111;
        tmp(i,1,1);
    }
    cout<<anss%998244353;


}
