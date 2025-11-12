#include <bits/stdc++.h>
using namespace std;

bool cmp(int n,int a){
    return n<a;
}
struct A{
    int a,b,c;
}h[102700];
vector<int>a,b,c;
int a1[102700],b1[102700],c1[102700],a2[102700],b2[102700],c2[102700];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        a.resize(0);
        b.resize(0);
        c.resize(0);
        int n,da=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>h[i].a>>h[i].b>>h[i].c;
            int man=-1,k=0;
            if(h[i].a>man){
                man=h[i].a;
                k=1;
            }
            if(h[i].b>man){
                man=h[i].b;
                k=2;
            }
            if(h[i].c>man){
                man=h[i].c;
                k=3;
            }
            if(k==1){a.push_back(h[i].a-max(h[i].b,h[i].c));da+=h[i].a;}
            else if(k==2) b.push_back(h[i].b-max(h[i].a,h[i].c)),da+=h[i].b;
            else if(k==3) c.push_back(h[i].c-max(h[i].b,h[i].a)),da+=h[i].c;
            //for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;
        }

        //cout<<da<<endl;
        //for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;
        //for(int i=0;i<b.size();i++)cout<<b[i]<<" ";cout<<endl;
        //for(int i=0;i<c.size();i++)cout<<c[i]<<" ";cout<<endl;
        if(a.size()>n/2){
            for(int i=0;i<a.size();i++){
                a1[i]=a[i];
            }
            sort(a1,a1+a.size(),cmp);
            //for(int i=0;i<a.size();i++)cout<<a1[i]<<" ";cout<<endl;
            if(a.size()%2==1)for(int i=0;i<a.size()-n/2;i++) da-=a1[i];
            else for(int i=0;i<a.size()-n/2;i++) da-=a1[i];
        }
        else if(b.size()>n/2){
            for(int i=0;i<b.size();i++){
                b1[i]=b[i];
            }
            sort(b1,b1+b.size(),cmp);
            //for(int i=0;i<b.size();i++)cout<<b1[i]<<" ";cout<<endl;
            if(b.size()%2==1)for(int i=0;i<b.size()-n/2;i++) da-=b1[i];
            else for(int i=0;i<b.size()-n/2;i++) da-=b1[i];
        }
        else if(c.size()>n/2){
            for(int i=0;i<c.size();i++){
                c1[i]=c[i];
            }
            sort(c1,c1+c.size(),cmp);
            //for(int i=0;i<c.size();i++)cout<<c1[i]<<" ";cout<<endl;
            if(c.size()%2==1)for(int i=0;i<c.size()-n/2;i++) da-=c1[i];
            else for(int i=0;i<c.size()-n/2;i++) da-=c1[i];
        }
        cout<<da<<endl;
    }
    return 0;
}
