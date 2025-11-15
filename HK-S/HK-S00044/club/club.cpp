#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct _{int a,b,c;bool f;}a[100005],b[100005],c[100005];
int t,n,s,f,g,h;
bool abcmp(_ x,_ y){return x.b-x.a>y.b-y.a;}
bool accmp(_ x,_ y){return x.c-x.a>y.c-y.a;}
bool bccmp(_ x,_ y){return x.c-x.b>y.c-y.b;}
bool cabcmp(_ x,_ y){x.f=x.a-x.c<x.b-x.c,y.f=y.a-y.c<y.b-y.c;return max(x.a-x.c,x.b-x.c)>max(y.a-y.c,y.b-y.c);}
bool baccmp(_ x,_ y){x.f=x.a-x.b<x.c-x.b,y.f=y.a-y.b<y.c-y.b;return max(x.a-x.b,x.c-x.b)>max(y.a-y.b,y.c-y.b);}
bool abccmp(_ x,_ y){x.f=x.b-x.a<x.c-x.a,y.f=y.b-y.a<y.c-y.a;return max(x.b-x.a,x.c-x.a)>max(y.b-y.a,y.c-y.a);}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;s=f=g=h=0;//printf("%d %d %d\n",f,g,h);
        for(int i=0;i<n;i++){scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);s+=a[i].a;}
        sort(a,a+n,abcmp);f=n;//printf("%d %d %d %d\n",n,a[0].a,a[0].b,a[0].c);
        for(int i=0;i<n&&f-g&&a[i].b>a[i].a;i++)b[g++]=a[i],s+=a[i].b-a[i].a,a[i].c=-1,f--;
        sort(a,a+n,accmp);sort(b,b+g,bccmp);
        for(int i=0,k=f;i<k&&a[i].c>a[i].a;i++)c[h++]=a[i],s+=a[i].c-a[i].a,a[i].a=a[i].b=-1,f--;
        for(int i=0,k=g;i<k&&b[i].c>b[i].b;i++)c[h++]=b[i],s+=b[i].c-b[i].b,b[i].a=b[i].b=-1,f--;
        //printf("%d %d %d\n",f,g,h);
        sort(c,c+h,cabcmp);
        for(int i=0;h>n/2;i++){
            s+=c[i].f?c[i].b-c[i].c:c[i].a-c[i].c;
        }sort(b,b+g,baccmp);
        for(int i=0;g>n/2;i++){
            s+=b[i].f?b[i].c-b[i].b:b[i].a-b[i].b;
        }sort(a,a+f,abccmp);
        for(int i=0;f>n/2;i++){
            s+=a[i].f?a[i].c-a[i].a:a[i].b-a[i].a;
        }cout<<s<<endl;
    }
    return 0;
}//g++ -O2 -std=c++14 -static club.cpp -o a