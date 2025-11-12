#include<bits/stdc++.h>
using namespace std;
int n,t,jieguo;
int xg;
struct df{
    int a;
    int b;
    int c;
    int zuida;
    int a1;
    int b1;
    int c1;
    int jzc;
};
int pan1(int x,int y,int z){
    if(x>=y&&x>=z){
        return x;
    }
    else if(y>=x&&y>=z){
        return y;
    }
    else if(z>=x&&z>=y){
        return z;
    }
}

int sjzc(int x,int y,int m){

    if(m-x<=m-y){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
    cin>>t;
    int z1,z2,jzcm;

    jzcm=0;
    for(int w=1;w<=t;w++){
        cin>>n;
        jieguo=0;
        int sx=n/2;
        struct df s[200005];
        for(int i=1;i<=n;i++){
            cin>>s[i].a>>s[i].b>>s[i].c;
            s[i].a1=0;s[i].b1=0;s[i].c1=0;
            s[i].zuida=pan1(s[i].a,s[i].b,s[i].c);
            if(s[i].zuida==s[i].a){
        s[i].a1=1;

    }
     else if(s[i].zuida==s[i].b){
        s[i].b1=1;

    }
    else if(s[i].zuida==s[i].c){
        s[i].c1=1;

    }
        }

        while(true){

                xg=0;
                int a2,b2,c2;
                for(int i=1;i<=n;i++){
                    if(s[i].a1==1){
                        a2++;
                    }
                    else if(s[i].b1==1){
                        b2++;
                    }
                    else if(s[i].c1==1){
                        c2++;
                    }

                }
                if(a2<=sx&&b2<=sx&&c2<=sx){
                    for(int i=1;i<=n;i++){
                    if(s[i].a1==1){
                    if(s[i].b1!=2){
                        z1=s[i].b;
                    }
                    else{
                        z1=-1e8;
                    }
                    if(s[i].c1!=2){
                        z2=s[i].c;
                    }
                    else{
                        z2=-1e8;
                    }
            }
            else if(s[i].b1==1){
                if(s[i].a1!=2){
                        z1=s[i].a;
                    }
                    else{
                        z1=-1e8;
                    }
                    if(s[i].c1!=2){
                        z2=s[i].c;
                    }
                    else{
                        z2=-1e8;
                    }
            }
            else if(s[i].c1==1){
                if(s[i].a1!=2){
                        z1=s[i].a;
                    }
                    else{
                        z1=-1e8;
                    }
                    if(s[i].b1!=2){
                        z2=s[i].b;
                    }
                    else{
                        z2=-1e8;
                    }
            }
            s[i].jzc=sjzc(z1,z2,s[i].zuida);
            z1=0;z2=0;jzcm=0;
                }

            for(int i=1;i<=n;i++){
                jzcm=min(jzcm,s[i].zuida-s[i].jzc);
            }
            //cout<<"jzcm"<<jzcm<<endl;
            for(int i=1;i<=n;i++){
                if(jzcm==s[i].zuida-s[i].jzc){
                    xg=i;
                    //cout<<"xg:"<<xg<<endl;
                    break;
                }
            }    //cout<<"#"<<s[xg].jzc<<endl;
            if(s[xg].jzc==s[xg].a){
                s[xg].a1=1;
                s[xg].b1=0;
                s[xg].c1=0;
                if(s[xg].zuida==s[xg].b){
                    s[xg].b1=2;
                }
                else if(s[xg].zuida==s[xg].c){
                    s[xg].c1=2;
                }
                s[xg].zuida=s[xg].a;

            }

            else if(s[xg].jzc==s[xg].b){
                s[xg].a1=0;
                s[xg].b1=1;
                s[xg].c1=0;
                if(s[xg].zuida==s[xg].a){
                    s[xg].a1=2;
                }
                else if(s[xg].zuida==s[xg].c){
                    s[xg].c1=2;
                }
                s[xg].zuida=s[xg].b;

            }
            else if(s[xg].jzc==s[xg].c){
                s[xg].a1=0;
                s[xg].b1=0;
                s[xg].c1=1;
                if(s[xg].zuida==s[xg].a){
                    s[xg].a1=2;
                }
                else if(s[xg].zuida==s[xg].b){
                    s[xg].b1=2;
                }
                s[xg].zuida=s[xg].c;

            }
                }
                else{
                    break;
                }

            }
           for(int i=1;i<=n;i++){
        if(s[i].a1==1){
            jieguo+=s[i].a;
           // cout<<s[i].a<<endl;
        }
        else if(s[i].b1==1){
            jieguo+=s[i].b;
          //  cout<<s[i].b<<endl;
        }
        else if(s[i].c1==1){
            jieguo+=s[i].c;
           // cout<<s[i].c<<endl;
        }
    }
    cout<<jieguo<<endl;


    }
}
