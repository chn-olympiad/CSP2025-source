#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int s,d,m,sss,h,l,c,p,w,b,u,j,ch[10000],zh;
    float dg;
    cin>>h>>l;
    for(int i=0;i<h*l;i++){
        cin>>ch[i];
    }
    zh=ch[0];
    for(int p=0;p<h*l;p++){
        for(int u=1;u<h*l;u++){
            if(ch[p]>ch[u-1]){
                b=ch[p];
                ch[p]=ch[u-1];
                ch[u-1]=b;
            }
        }
    }
    for(int j=0;j<h*l;j++){
        if(ch[j]<zh){
            d=j+1;
            break;
        }
    }



    m=d%h;




    s=int(d)/int(h);
    sss=s;
    if(sss%2==0){
        cout<<sss+1<<m+1;
    }
    else{
        cout<<sss<<h-m+1;
    }
    return 0;
}
