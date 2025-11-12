#include<bits/stdc++.h>
using namespace std;//Ren5Jie4Di4Ling5%
int t;
int n;
int p;
int ans;
int a,b,c;
int j,jj,jjj,mi;
int xu(int d,int e,int f){
    if(d>e&&d>f){
        if(a<p){
            a+1;
            ans=ans+d;
            return 0;
        }else{
            d=0;
            xu(d,e,f);
        }

    }
    if(e>d&&e>f){
        if(b<p){
            b+1;
            ans=ans+e;
            return 0;
        }else{
            e=0;
            xu(d,e,f);
        }


    }
    if(f>d&&f>e){
        if(c<p){
            c+1;
            ans=ans+f;
            return 0;
    }else{
        f=0;
        xu(d,e,f);
    }
}

}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        p=n/2;
        ans=0;
        int aa[100001]{0};
        int bb[100001]{0};
        int cc[100001]{0};
        for(int l=1;l<=n;l++){
            cin>>j>>jj>>jjj;
            xu(j,jj,jjj);

            }
        cout<<ans<<endl;
        }
    return 0;

    }


