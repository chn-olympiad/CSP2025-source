#include<bits/stdc++.h>
using namespace std;
int m,n=0,k,i,p,b;
struct f{
    int num;
    bool b=0;
}a[100000000];

int digui(int k,int d,int c)
{
    if(c>m){
        digui(k,d+1,c+1);
    }
    if(d>m){
        return n;
    }
    for(int i=d;i<=c;i++){
        p+=a[i].b;
    }
    if(p==0){
        for(int i=d+1;i<=c;i++){
        if(i==d+1){
            b=(a[i].num^a[i+1].num);
        }
        b=(b^a[i].num);
        a[i].b=1;
    }
    if(b==k){
        n++;
    }

    a[d].b=1;
    digui(k,d,c+1);
    for(int i=d;i<=c;i++){
        a[i].b=0;
    }
    }


}
int main(){
    cin>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].num;

    }
    digui(k,1,1);
    cout<<n;


}
