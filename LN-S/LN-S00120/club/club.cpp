#include<bits/stdc++.h>
using namespace std;
#define int long long
struct people{
    int x,y,z;
    static bool camp(people a,people b){
        return a.x>b.x;
    }
    static bool cbmp(people a,people b){
        return a.y>b.y;
    }
    static bool ccmp(people a,people b){
        return a.z>b.z;
    }
    people(int a,int b,int c){x=a,y=b,z=c;}
};
void sol(){
    int n,sum=0;
    cin>>n;
    vector<people>v;
    for(int i=0;i<n;i++){int tmp1,tmp2,tmp3;cin>>tmp1>>tmp2>>tmp3;v.emplace_back(tmp1,tmp2,tmp3);}
    vector<people>non,a,b,c;
    bool fa=0,fb=0,fc=0;
    for(auto i:v){
        int tmp=max(i.x,max(i.y,i.z));
        if((i.x==i.y)&&(tmp==i.x)){
            non.emplace_back(i);
            continue;
        }
        if((i.x==i.z)&&(tmp==i.x)){
            non.emplace_back(i);
            continue;
        }
        if((i.z==i.y)&&(tmp==i.z)){
            non.emplace_back(i);
            continue;
        }
        if(tmp==i.x)a.emplace_back(i);
        if(tmp==i.y)b.emplace_back(i);
        if(tmp==i.z)c.emplace_back(i);
        if(a.size()*2>v.size()){
            fa=1;
            sort(a.begin(),a.end(),people::camp);
            while(a.size()*2>v.size()){
                a[a.size()-1].x=-1;
                non.emplace_back(a[a.size()-1]);
                a.pop_back();
            }
        }
        if(b.size()*2>v.size()){
            fb=1;
            sort(b.begin(),b.end(),people::cbmp);
            while(b.size()*2>v.size()){
                b[b.size()-1].y=-1;
                non.emplace_back(b[b.size()-1]);
                b.pop_back();
            }
        }
        if(c.size()*2>v.size()){
            fc=1;
            sort(c.begin(),c.end(),people::ccmp);
            while(c.size()*2>v.size()){
                c[c.size()-1].z=-1;
                non.emplace_back(c[c.size()-1]);
                c.pop_back();
            }
        }
    }
    sort(non.begin(),non.end(),[&](people a,people b){
        int mxa=0;
        if(!fa)mxa=max(mxa,a.x);
        if(!fb)mxa=max(mxa,a.y);
        if(!fc)mxa=max(mxa,a.z);
        int mxb=0;
        if(!fa)mxb=max(mxb,b.x);
        if(!fb)mxb=max(mxb,b.y);
        if(!fc)mxb=max(mxb,b.z);
        return mxa>mxb;
    });
    for(auto i:non){
        int tmp=max(i.x,max(i.y,i.z));
        if((i.x==i.y)&&(tmp==i.x)){
            non.emplace_back(i);
            continue;
        }
        if((i.x==i.z)&&(tmp==i.x)){
            non.emplace_back(i);
            continue;
        }
        if((i.z==i.y)&&(tmp==i.z)){
            non.emplace_back(i);
            continue;
        }
        if(tmp==i.x)a.emplace_back(i);
        if(tmp==i.y)b.emplace_back(i);
        if(tmp==i.z)c.emplace_back(i);
        if(a.size()*2>v.size()){
            fa=1;
            sort(a.begin(),a.end(),people::camp);
            while(a.size()*2>v.size()){
                a[a.size()-1].x=-1;
                non.emplace_back(a[a.size()-1]);
                a.pop_back();
            }
        }
        if(b.size()*2>v.size()){
            fb=1;
            sort(b.begin(),b.end(),people::cbmp);
            while(b.size()*2>v.size()){
                b[b.size()-1].y=-1;
                non.emplace_back(b[b.size()-1]);
                b.pop_back();
            }
        }
        if(c.size()*2>v.size()){
            fc=1;
            sort(c.begin(),c.end(),people::ccmp);
            while(c.size()*2>v.size()){
                c[c.size()-1].z=-1;
                non.emplace_back(c[c.size()-1]);
                c.pop_back();
            }
        }
    }
    for(int i=0;i<non.size();i++){
        int tmp=max(non[i].x,max(non[i].y,non[i].z));
        if((non[i].x==non[i].y)&&(tmp==non[i].x)){
            continue;
        }
        if((non[i].x==non[i].z)&&(tmp==non[i].x)){
            continue;
        }
        if((non[i].z==non[i].y)&&(tmp==non[i].z)){
            continue;
        }
        if(tmp==non[i].x)a.emplace_back(non[i]);
        if(tmp==non[i].y)b.emplace_back(non[i]);
        if(tmp==non[i].z)c.emplace_back(non[i]);
        if(a.size()*2>v.size()){
            fa=1;
            sort(a.begin(),a.end(),people::camp);
            while(a.size()*2>v.size()){
                a[a.size()-1].x=-1;
                non.emplace_back(a[a.size()-1]);
                a.pop_back();
            }
        }
        if(b.size()*2>v.size()){
            fb=1;
            sort(b.begin(),b.end(),people::cbmp);
            while(b.size()*2>v.size()){
                b[b.size()-1].y=-1;
                non.emplace_back(b[b.size()-1]);
                b.pop_back();
            }
        }
        if(c.size()*2>v.size()){
            fc=1;
            sort(c.begin(),c.end(),people::ccmp);
            while(c.size()*2>v.size()){
                c[c.size()-1].z=-1;
                non.emplace_back(c[c.size()-1]);
                c.pop_back();
            }
        }
    }
    for(int i=0;i<non.size();i++){
        int tmp=max(non[i].x,max(non[i].y,non[i].z));
        if((non[i].x==non[i].y)&&(tmp==non[i].x)){
            continue;
        }
        if((non[i].x==non[i].z)&&(tmp==non[i].x)){
            continue;
        }
        if((non[i].z==non[i].y)&&(tmp==non[i].z)){
            continue;
        }
        if(tmp==non[i].x)a.emplace_back(non[i]);
        if(tmp==non[i].y)b.emplace_back(non[i]);
        if(tmp==non[i].z)c.emplace_back(non[i]);
        if(a.size()*2>v.size()){
            fa=1;
            sort(a.begin(),a.end(),people::camp);
            while(a.size()*2>v.size()){
                a[a.size()-1].x=-1;
                non.emplace_back(a[a.size()-1]);
                a.pop_back();
            }
        }
        if(b.size()*2>v.size()){
            fb=1;
            sort(b.begin(),b.end(),people::cbmp);
            while(b.size()*2>v.size()){
                b[b.size()-1].y=-1;
                non.emplace_back(b[b.size()-1]);
                b.pop_back();
            }
        }
        if(c.size()*2>v.size()){
            fc=1;
            sort(c.begin(),c.end(),people::ccmp);
            while(c.size()*2>v.size()){
                c[c.size()-1].z=-1;
                non.emplace_back(c[c.size()-1]);
                c.pop_back();
            }
        }
    }
    for(int i=0;i<non.size();i++){
        int tmp=max(non[i].x,max(non[i].y,non[i].z));
        if((non[i].x==non[i].y)&&(tmp==non[i].x)){
            int tmp2=max(fa?0:a.size(),b.size());
            if(!fa&&(tmp2==a.size()))a.emplace_back(non[i]);
            else if(!fb)b.emplace_back(non[i]);
            continue;
        }
        if(a.size()*2>v.size())fa=true;
        if((non[i].x==non[i].z)&&(tmp==non[i].x)){
            int tmp2=max(fa?0:a.size(),c.size());
            if(!fa&&(tmp2==a.size()))a.emplace_back(non[i]);
            else if(!fc)c.emplace_back(non[i]);
            continue;
        }
        if(a.size()*2>v.size())fa=true;
        if((non[i].z==non[i].y)&&(tmp==non[i].z)){
            int tmp2=max(fc?0:c.size(),b.size());
            if(!fc&&(tmp2==c.size()))c.emplace_back(non[i]);
            else if(!fb)b.emplace_back(non[i]);
            continue;
        }
        cerr<<non[i].x<<' '<<non[i].y<<' '<<non[i].z;
    }
    for(auto i:a)sum+=i.x;
    for(auto i:b)sum+=i.y;
    for(auto i:c)sum+=i.z;
    cout<<sum;
    
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        sol();
        cout<<"\n";
    }
}