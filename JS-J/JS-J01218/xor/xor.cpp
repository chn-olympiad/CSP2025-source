#include<bits/stdc++.h>
using namespace std;
int a,b,c[500001],ranges[500001][2],s=0,k=0,lastend=0;
void makesort(){
    for(int i=s-1;i>=1;i--){
        int f=1;
        for(int j=1;j<=i;j++){
            if(ranges[j][1]>ranges[j+1][1]){
                swap(ranges[j][1],ranges[j+1][1]);
                swap(ranges[j][0],ranges[j+1][0]);
                f=0;
            }
        }
        if(f){
            break;
        }
    }
}
int _xor(int a,int b){
    return (a|b)-(a&b);
}
int sxor(int x,int y){
    int r=c[x];
    for(int i=x+1;i<=y;i++){
        r=_xor(r,c[i]);
    }
    return r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
    }
    for(int i=1;i<=a;i++){
        for(int j=i;j<=a;j++){
            if(sxor(i,j)==b){
                ranges[++s][0]=i;
                ranges[s][1]=j;
            }
        }
    }

    makesort();
    for(int i=1;i<=s;i++){
        if(ranges[i][0]>lastend){
            lastend=ranges[i][1];
            k++;
        }
    }
    cout<<k;
    return 0;
}
