#include<bits/stdc++.h>
using namespace std;
struct manyi{
    int a;
    int b;
    int c;
    int ch;
}w[1000005],m1[1000005],m2[1000005],m3[1000005];
int mn1=1,mn2=1,mn3=1;
int n;
long long man;
int t;
bool cmp(manyi o,manyi p){
    return o.ch>p.ch;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i].a>>w[i].b>>w[i].c;
        if(w[i].a>=w[i].b && w[i].a>=w[i].c){
            m1[mn1].a=w[i].a;
            m1[mn1].b=w[i].b;
            m1[mn1].c=w[i].c;
            m1[mn1++].ch=min(w[i].a-w[i].b,w[i].a-w[i].c);
            man+=w[i].a;
        }else

        if(w[i].b>=w[i].c && w[i].b>=w[i].a){
            m2[mn2].a=w[i].a;
            m2[mn2].b=w[i].b;
            m2[mn2].c=w[i].c;
            m2[mn2++].ch=min(w[i].b-w[i].c,w[i].b-w[i].a);
            man+=w[i].b;
        }else
        if(w[i].c>=w[i].b && w[i].c>=w[i].a){
            m3[mn3].a=w[i].a;
            m3[mn3].b=w[i].b;
            m3[mn3].c=w[i].c;
            m3[mn3++].ch=min(w[i].c-w[i].b,w[i].c-w[i].a);
            man+=w[i].c;
        }
    }
// cout<<mn1<<" "<<mn2<<" "<<mn3<<" "<<man;
    if(mn1>n/2){
        sort(m1+1,m1+mn1+1,cmp);
        while(mn1>n/2){
            cout<<"out "<< m1[mn1].ch <<endl;
            man-=m1[mn1--].ch;
        }
    }
    if(mn2>n/2){
        sort(m2+1,m2+mn2+1,cmp);
        while(mn2>n/2){
            man-=m2[mn2--].ch;
        }
    }
    if(mn3>n/2){
        sort(m3+1,m3+mn3+1,cmp);
        while(mn3>n/2){
            man-=m3[mn3--].ch;
        }
    }
    cout<<man<<endl;
    mn1=1;
    mn2=1;
    mn3=1;
    n=0;
    man=0;
    }
return 0;
}
