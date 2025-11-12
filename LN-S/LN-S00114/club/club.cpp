#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(int w,int v){
    return w>v;
}
int z=0,xz=0,a=0,b=0,c=0,x=0,m[2147483647]={};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int al[1000001]={},as=0,bs=0,cs=0;
    int bl[1000001]={},cl[1000001]={};
    cin>>z;
    for(int i=1;i<=z;++i){
        cin>>xz;
        x=xz/2;
        memset(al,0,sizeof(al));
        memset(bl,0,sizeof(bl));
        memset(cl,0,sizeof(cl));
        int maza=0;
        int mazb=0;
        int mazc=0;
        for(int j=1;j<=xz;++j){
            cin>>a>>b>>c;
            if(a>b&&a>c&&as<x){
                al[j]=a;
                as++;
            }
            else if(b>a&&b>c&&bs<x){
                bl[j]=b;
                bs++;
            }
            else if(c>b&&c>a&&cs<x){
                cl[j]=c;
                cs++;
            }
        }
        sort(al,al+as,cmp);
        sort(bl,bl+bs,cmp);
        sort(cl,cl+cs,cmp);
        for(int j=0;j<=x;j++){
            maza=al[j]+maza;
            mazb=bl[j]+mazb;
            mazc=cl[j]+mazc;
        }
        m[i]=maza+mazb+mazc;
    }
    for(int i=1;i<=z;++i){
        cout<<m[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
