#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t,m,cnt,s[10][3],l1[100010],l2[100010],l3[100010],mx[100010],wh[100010],swh[100010],twh[100010],sma[100010],tma[100010];
void _count(){
    for(int i=1;i<=n;i++){
        if(s[1][wh[i]<m]){
            s[1][wh[i]]++;
            cnt+=mx[i];
        }else if( s[1][swh[i]]<m){
            s[1][swh[i]]++;
            cnt+=sma[i];
        }else{
            s[1][twh[i]]++;
            cnt+=tma[i];
        }
    }

}


 void _swap(ll a,ll b){


    ll a1,a2,a3,a4,a5,a6,a7,a8,a9;
    a1=l1[b];
    a2=l2[b];
    a3=l3[b];
    a4=mx[b];
    a5=wh[b];
    a6=swh[b];
    a7=sma[b];
    a8=twh[b];
    a9=tma[b];



    l1[b]=l1[a];
    l2[b]=l2[a];
    l3[b]=l3[a];
    mx[b]=mx[a];
    wh[b]=wh[a];
    sma[b]=sma[a];
    swh[b]=swh[a];
    tma[b]=tma[a];
    twh[b]=twh[a];

    l1[a]=a1;
    l2[a]=a2;
    l3[a]=a3;
    mx[a]=a4;
    wh[a]=a5;
    swh[b]=a6;
    sma[b]=a7;
    twh[b]=a8;
    tma[b]=a9;


 }
void change(){
    ll l=1,r=2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(wh[i]<wh[j]){
                _swap(i,j);
            }
            if(wh[i]==wh[j]&&mx[i]<mx[j]){
                _swap(i,j);
            }
            if(wh[i]>=wh[j]&&mx[i]>=mx[j]){
                break;
            }


        }

    }
    while(r==n){
        if(wh[r]<wh[l]){
            _swap(l,r);

        }
        l++;
        r++;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(swh[i]<swh[j]&&wh[i]==wh[j]){
                _swap(i,j);
            }
            if(swh[i]==swh[j]&&sma[i]<sma[j]&&wh[i]==wh[j]&&mx[i]==mx[j]){
                _swap(i,j);
            }
            if(swh[i]>=swh[j]&&sma[i]>=sma[j]){
                break;
            }


        }

    }
    while(r==n){
        if(swh[r]<swh[l]){
            _swap(l,r);

        }
        l++;
        r++;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(swh[i]<swh[j]&&wh[i]==wh[j]){
                _swap(i,j);
            }
            if(swh[i]==swh[j]&&sma[i]<sma[j]&&wh[i]==wh[j]&&mx[i]==mx[j]){
                _swap(i,j);
            }
            if(swh[i]>=swh[j]&&sma[i]>=sma[j]){

                break;
            }


        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(twh[i]<twh[j]&&wh[i]==wh[j]&&swh[i]==swh[j]&&mx[i]==mx[j]){
                _swap(i,j);
            }
            if(twh[i]==twh[j]&&tma[i]<tma[j]&&wh[i]==wh[j]&&mx[i]==mx[j]&&swh[i]==swh[j]&&mx[i]==mx[j]&&sma[i]==sma[j]){
                _swap(i,j);
            }
            if(twh[i]>=twh[j]&&tma[i]>=tma[j]){
                    break;
            }


        }

    }
    while(r==n){
        if(twh[r]<twh[l]){
            _swap(l,r);

        }
        l++;
        r++;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(twh[i]<twh[j]&&wh[i]==wh[j]&&swh[i]==swh[j]&&mx[i]==mx[j]){
                _swap(i,j);
            }
            if(twh[i]==twh[j]&&tma[i]<tma[j]&&wh[i]==wh[j]&&mx[i]==mx[j]&&swh[i]==swh[j]&&mx[i]==mx[j]&&sma[i]==sma[j]){
                _swap(i,j);
            }
            if(twh[i]>=twh[j]&&tma[i]>=tma[j]){
                break;

            }


        }

    }
}
void setup(){
for(int i=0;i<100100;i++){
    l1[i]=0;
    l2[i]=0;
    l3[i]=0;
    mx[i]=-1e18;
    wh[100010]=0;
    swh[100010]=0;
    twh[100010]=0;
    sma[100010]=0;
    tma[100010]=0;
    cnt=0;
    n=0;
}


}

int main(){
    //freopen("club.in","w",stdin);
    //freopen("club.out","r",stdout);
    cin>>t;
    while(t--){
        setup();
        cin>>n;
        m=n/2;
        for(int i=1;i<=n;i++){
            cin>>l1[i]>>l2[i]>>l3[i];
            mx[i]=max(l1[i],l2[i]);
            mx[i]=max(mx[i],l3[i]);
            if(mx[i]==l1[i]){
                wh[i]=1;
                sma[i]=max(l2[i],l3[i]);
                tma[i]=max(l2[i],l3[i]);

            if(sma[i]==l2[i]){
                sma[i]=2;
                tma[i]=3;
                swh[i]=2;
                twh[i]=3;
            }
            if(sma[i]==l3[i]){
                sma[i]=3;
                tma[i]=2;
                swh[i]=3;
                twh[i]=2;
            }
            }
            if(mx[i]==l2[i]){
                wh[i]=2;
                sma[i]=max(l1[i],l3[i]);
                tma[i]=max(l1[i],l3[i]);
                if(sma[i]==l1[i]){
                    sma[i]=1;
                    tma[i]=3;
                    swh[i]=1;
                    twh[i]=3;
                }
                if(sma[i]==l3[i]){
                    sma[i]=3;
                    tma[i]=1;
                    swh[i]=3;
                    twh[i]=1;
                }

            }
            if(mx[i]==l3[i]){
                wh[i]=3;
                sma[i]=max(l2[i],l1[i]);
                tma[i]=max(l2[i],l1[i]);
                if(sma[i]==l1[i]){
                    sma[i]=1;
                    tma[i]=2;
                    swh[i]=1;
                    twh[i]=2;
                }
                if(sma[i]==l2[i]){
                    sma[i]=2;
                    tma[i]=1;
                    swh[i]=2;
                    twh[i]=1;
                }


            }

        }
        change();
       // for(int i=1;i<=n;i++){
        //    cout<<l1[i]<<"    "<<l2[i]<<"    "<<l3[i]<<"    "<<mx[i]<<"    "<<wh[i]<<endl;
        //}
         _count();
         cout<<cnt;
    }



    return 0;
}
