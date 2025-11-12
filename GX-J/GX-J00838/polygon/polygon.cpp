#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,m[5001]={},o=0;
cin>>n;
for(int i=0;i<n;i++){
    cin>>m[i];
}
for(int i=0;i<n;i++){
        int b=m[i],p=m[i];
    for(int j=i+1;j<n;j++){
        int jq=0;
        p+=m[j];
        if(m[j]>b)b=m[j];
        if(p>=b*2)o++;
        for(int v=i+1;v<j;v++){
            if(p-m[v]>=b*2){o++;
            p-=m[v];jq+=m[v];
    }
        }p+=jq;
    }
}cout<<o;
return 0;
}
