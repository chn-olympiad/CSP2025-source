#include<bits/stdc++.h>
using namespace std;
int aa,bb,cc;
int am[100356],bm[100023],cm[100034];
long long gg[103846];
struct ss{
    int a,b,c;
    int ab,ac,bc;
}aq[1030392];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++){
        memset(gg,0x3f,sizeof(gg));
        memset(am,0,sizeof(am));
        memset(bm,0,sizeof(bm));
        memset(cm,0,sizeof(cm));
        int n;
        cin>>n;
        int uu=n/2;
        for(int i=1;i<=n;i++){
            cin>>aq[i].a>>aq[i].b>>aq[i].c;
            aq[i].ab=max(aq[i].a,aq[i].b)-min(aq[i].a,aq[i].b);
            aq[i].ac=max(aq[i].a,aq[i].c)-min(aq[i].a,aq[i].c);
            aq[i].bc=max(aq[i].c,aq[i].b)-min(aq[i].c,aq[i].b);
            if(aq[i].a>=aq[i].b&&aq[i].a>=aq[i].c){
                am[i]=1;
                continue;
            }
            if(aq[i].b>=aq[i].a&&aq[i].b>=aq[i].c){
                bm[i]=1;
                continue;
            }
            if(aq[i].c>=aq[i].a&&aq[i].c>=aq[i].b){
                cm[i]=1;
                continue;
            }
        }
        int cnta=0,cntb=0,cntc=0;
        long long ao=0,bo=0,co=0;
        for(int i=1;i<=n;i++){
            if(am[i]==1){
                ao+=aq[i].a;
                cnta++;
            }
            else if(bm[i]==1){
                bo+=aq[i].b;
                cntb++;
            }
            else if(cm[i]==1){
                co+=aq[i].c;
                cntc++;
            }
        }

        if(cnta<=uu&&cntb<=uu&&cntc<=uu){
            cout<<ao+bo+co<<endl;
            //cout<<"******";
            continue;
            //cout<<" "<<cnta<<" "<<cntb<<" "<<cntc;
        }else{
            if(cnta>uu){
                for(int i=1;i<=n;i++){
                    if(am[i]==1){
                        //cout<<1<<endl;
                        gg[i]=min(aq[i].ab,aq[i].ac);

                    }
                }
                sort(gg+1,gg+1+n);
                for(int i=1;i<=cnta-uu;i++){
                    ao-=gg[i];
                }
                cout<<ao+bo+co<<endl;
                continue;
            }
            if(cntb>uu){
                //cout<<1;
                for(int i=1;i<=n;i++){
                    if(bm[i]==1){
                        //cout<<2<<endl;
                        gg[i]=min(aq[i].ab,aq[i].bc);

                    }
                }
                sort(gg+1,gg+1+n);
                for(int i=1;i<=cntb-uu;i++){
                    bo-=gg[i];
                    //cout<<ao;
                }
                cout<<ao+bo+co<<endl;
                continue;
            }
            if(cntc>=uu){
                for(int i=1;i<=n;i++){
                    if(cm[i]==1){
                        //cout<<3<<endl;
                        gg[i]=min(aq[i].ac,aq[i].bc);

                    }
                }
                sort(gg+1,gg+1+n);
                for(int i=1;i<=cntc-uu;i++){
                    co-=gg[i];
                }
                cout<<ao+bo+co<<endl;
                continue;
            }



        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
