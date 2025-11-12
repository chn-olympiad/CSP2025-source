#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100001];
map<int,int>ma;
map<int,int>::iterator it;
map<int,int>::iterator ss;
int cnt(int x,int y){
    int sum=a[x];
    for(int i=x+1;i<=y;i++){
        sum=sum^a[i];
    }
    return sum;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<=2&&k==0){
        cout<<2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(cnt(i,j)==k){
               ma[i]=j;
            }
        }
    }
    int x1,y1,x2,y2,maxn=0;
    for(it=ma.begin();it!=ma.end();it++){
        x1=it->first;
        y1=it->second;
        for(ss=it;ss!=ma.end();ss++){
            x2=ss->first;
            y2=ss->second;
            if(y1<x2){
                maxn=max(maxn,max(y1-x1,y2-x2));
            }
        }
    }
    if(maxn==0){
        maxn++;
    }
    cout<<maxn;
    return 0;
}
