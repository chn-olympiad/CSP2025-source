#include<bits/stdc++.h>
using namespace std;



struct Me{
    int x,y,z;
};
Me a[100010];

int cmp(int x,int y){
    return x>y;
}
int cmp_B(int x,int y);


int b1[100010],b2[100010],b3[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a)/sizeof(a[0]));
        memset(b1,0,sizeof(b1)/sizeof(b1[0]));
        memset(b2,0,sizeof(b2)/sizeof(b2[0]));
        memset(b3,0,sizeof(b3)/sizeof(b3[0]));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>b1[i]>>b2[i]>>b3[i];
        }
        int ans=0;

        if(n==2){
                int f1=max(b1[0]+b2[1],b1[0]+b3[1]);
                int f2=max(f1,b2[0]+b1[1]);
                int f3=max(f2,b2[0]+b3[1]);
                int f4=max(f3,b2[0]+b3[1]);
                int f5=max(f4,b3[0]+b1[1]);
                int f6=max(f5,b3[0]+b2[1]);
                ans=f6;
                goto fin;
        }

//特判A
        for(int i=0;i<n;i++){if(b2[i]!=0 or b3[i]!=0)goto tpB;}
        //for(int i=0;i<=(n/2);i++)cout<<b1[i]<<endl;
        sort(b1,b1+(sizeof(b1)/sizeof(b1[0])),cmp);
        for(int i=0;i<=(n/2);i++)ans+=b1[i];
        goto fin;

//特判B
        tpB:
            for(int i=0;i<n;i++){
                if(b3[i]!=0)goto tp_n;
            }


//普通情况
        tp_n:

        fin:
            cout<<ans<<endl;
    }
return 0;
}
