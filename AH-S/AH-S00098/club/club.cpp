#include<bits/stdc++.h>
using namespace std;
int t,n;
struct nod{
    int a,b,c;
}s[100010];
int h1,h2,h3,as;
struct k{
    int x,y;
}d[100010];
int f(int a,int b,int c){
    int dd=max(a,max(b,c));
    if(dd==a){
        h1++;
        return a;
    }else if(dd==b){
        h2++;
        return b;
    }else{
        h3++;
        return c;
    }
}
int f2(int a,int b,int c){
    if(a>=b&&a>=c){
        return max(b,c);
    }else if(b>=a&&b>=c){
        return max(a,c);
    }else{
        return max(a,b);
    }
}
bool m(k g,k h){
    return g.x-g.y<h.x-h.y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            d[i].x=f(s[i].a,s[i].b,s[i].c);
            d[i].y=f2(s[i].a,s[i].b,s[i].c);
            as+=d[i].x;
        }
        sort(d,d+n,m);
        while(h1>n/2){
            int j=0;
            as-=d[j].x-d[j].y;
            h1--;
            j++;
        }
        while(h2>n/2){
            int j=0;
            as-=d[j].x-d[j].y;
            h2--;
            j++;
        }
        while(h3>n/2){
            int j=0;
            as-=d[j].x-d[j].y;
            h3--;
            j++;
        }
        cout<<as<<endl;
        as=0,h1=0,h2=0,h3=0;
        for(int i=0;i<=n;i++){
            d[i].x=0;
            d[i].y=0;
        }
    }
    return 0;
}
