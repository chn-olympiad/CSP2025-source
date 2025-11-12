#include<bits/stdc++.h>
using namespace std;
long long jh=0,t[5000];
void fdg(long long r,long long h){
    long long c,max1,o,p,flag=1;
    if(5000-h<3){
        return 0;
    }
    for(i=0;i<n;i++){
        c=r;
        c-=a[i];
        max1=0;
        for(o=0;o<n;o++){
            if(a[o]>max1){
                flag=1;
                for(p=0;p<h;p++){
                    if(o==t[p]){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    max1=a[o];
                }
            }
        }
        if(c>2*max1){
            jh++;
        }
        for()
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,i=0,max1=0,add=0,c,o=0;
    cin>>n;
    long long a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<5000;i++){
        t[i]=0;
    }
    for(i=0;i<n;i++){
        add+=a[i];
        if(a[i]>max1){max1=a[i];}
    }
    if(add>2*max1){
        jh++;
    }

    cout<<jh;
    retun 0;
}
