#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,x,y,z;
struct nod{
    int a,b,c,m;
    nod(int g,int y3,int tyr,int yt):a(g),b(y3),c(tyr),m(yt){}
};
bool cmp(nod a1,nod a2){
    return a1.m>a2.m;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        vector<nod>d3;
        int s1=0,s2=0,s3=0,ans=0; 
        cin>>n;
        int yy=n/2;
        for(int i=0;i<n;i++){
            cin>>x>>y>>z;
            int td=max(x,max(y,z));
            d3.push_back(nod(x,y,z,td));
        }
        sort(d3.begin(),d3.end(),cmp);
        for(int i=n-1;i>=0;i--){
        if(d3[i].m==d3[i].a){
        if(s1!=yy)s1++,ans+=d3[i].a;
        else if(max(d3[i].b,d3[i].c)==d3[i].b){
            if(s2!=yy)s2++,ans+=d3[i].b;        
             else s3++,ans+=d3[i].c;
        }
        else s3++,ans+=d3[i].c;
        }
        else if(d3[i].m==d3[i].b){
           if(s2!=yy)s2++,ans+=d3[i].b;
        else if(max(d3[i].a,d3[i].c)==d3[i].a){
            if(s1!=yy)s1++,ans+=d3[i].a;        
             else s3++,ans+=d3[i].c;
        }
        else s3++,ans+=d3[i].c;
        }
        else {
                  if(s3!=yy)s3++,ans+=d3[i].c;
        else if(max(d3[i].a,d3[i].b)==d3[i].a){
            if(s1!=yy)s1++,ans+=d3[i].a;        
             else s2++,ans+=d3[i].b;
        }
        else s2++,ans+=d3[i].b;
        }
        }
        int num=ans;
        ans=s1=s2=s3=0;
        for(int i=0;i<n;i++){
        if(d3[i].m==d3[i].a){
        if(s1!=yy)s1++,ans+=d3[i].a;
        else if(max(d3[i].b,d3[i].c)==d3[i].b){
            if(s2!=yy)s2++,ans+=d3[i].b;        
             else s3++,ans+=d3[i].c;
        }
        else s3++,ans+=d3[i].c;
        }
        else if(d3[i].m==d3[i].b){
           if(s2!=yy)s2++,ans+=d3[i].b;
        else if(max(d3[i].a,d3[i].c)==d3[i].a){
            if(s1!=yy)s1++,ans+=d3[i].a;        
             else s3++,ans+=d3[i].c;
        }
        else s3++,ans+=d3[i].c;
        }
        else {
                  if(s3!=yy)s3++,ans+=d3[i].c;
        else if(max(d3[i].a,d3[i].b)==d3[i].a){
            if(s1!=yy)s1++,ans+=d3[i].a;        
             else s2++,ans+=d3[i].b;
        }
        else s2++,ans+=d3[i].b;
        }
        }
        cout<<max(num,ans)<<endl;
    }
    return 0;
}