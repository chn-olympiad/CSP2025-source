#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int a,b,c;
}s[100005];
bool cm(int m,int q){
    return m>q;
}
bool cmp(node x,node y){
    int xp[5]={},yp[5]={};
    xp[1]=x.a;
    xp[2]=x.b;
    xp[3]=x.c;
    yp[1]=y.a;
    yp[2]=y.b;
    yp[3]=y.c;
    sort(xp+1,xp+4,cm);
    sort(yp+1,yp+4,cm);
    if((xp[1]-xp[2])!=(yp[1]-yp[2])){
        return (xp[1]-xp[2])>(yp[1]-yp[2]);
    }
    else{
        return (xp[2]-xp[3])>(yp[2]-yp[3]);
    }

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
        }
        sort(s+1,s+n+1,cmp);
        int as=0,bs=0,cs=0,sx=n/2,kx=0;
        for(int i=1;i<=n;i++){
            if(s[i].a>=s[i].b&&s[i].a>=s[i].c){
                if(as<sx){
                    as++;
                    kx+=s[i].a;
                }
                else{
                    if(s[i].b>=s[i].c){
                        if(bs<sx){
                            bs++;
                            kx+=s[i].b;
                        }
                        else{
                            cs++;
                            kx+=s[i].c;
                        }
                    }
                    else{
                        if(cs<sx){
                            cs++;
                            kx+=s[i].c;
                        }
                        else{
                            bs++;
                            kx+=s[i].b;
                        }
                    }
                }
            }
            else if(s[i].b>=s[i].a&&s[i].b>=s[i].c){
                if(bs<sx){
                    bs++;
                    kx+=s[i].b;
                }
                else{
                    if(s[i].a>=s[i].c){
                        if(as<sx){
                            as++;
                            kx+=s[i].a;
                        }
                        else{
                            cs++;
                            kx+=s[i].c;
                        }
                    }
                    else{
                        if(cs<sx){
                            cs++;
                            kx+=s[i].c;
                        }
                        else{
                            as++;
                            kx+=s[i].a;
                        }
                    }
                }
            }
            else if(s[i].c>=s[i].a&&s[i].c>=s[i].b){
                if(cs<sx){
                    cs++;
                    kx+=s[i].c;
                }
                else{
                    if(s[i].a>=s[i].b){
                        if(as<sx){
                            as++;
                            kx+=s[i].a;
                        }
                        else{
                            bs++;
                            kx+=s[i].b;
                        }
                    }
                    else{
                        if(bs<sx){
                            bs++;
                            kx+=s[i].b;
                        }
                        else{
                            as++;
                            kx+=s[i].a;
                        }
                    }
                }
            }
        }
    cout<<kx<<endl;
    }
    return 0;
}