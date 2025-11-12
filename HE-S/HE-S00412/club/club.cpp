#include <bits/stdc++.h>
using namespace std;
int com(int a,int b,int c){
    if(a>b and a>c){
        return 1;
    }
    if(b>a and b>c){
        return 2;
    }
    if(c>a and c>b){
        return 3;
    }

}
int com2(int a,int b,int c){
    if(com(a,b,c)==1){
        if(max(b,c)==b){
            return 2;
        }
        else{
            return 3;
        }
    }
    if(com(a,b,c)==2){
        if(max(a,c)==a){
            return 1;
        }
        else{
            return 3;
        }
    }
    if(com(a,b,c)==3){
        if(max(a,b)==b){
            return 2;
        }
        else{
            return 1;
        }
    }

}
int com3(int a,int b,int c){
    if(com(a,b,c)==1 and com2(a,b,c)==2){
        return 3;
    }
    if(com(a,b,c)==1 and com2(a,b,c)==3){
        return 2;
    }
    if(com(a,b,c)==2 and com2(a,b,c)==3){
        return 1;
    }
}
int cnt[10],n,t,ans=0,id,a,b,c;
int main()
{   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a>>b>>c;
            if(b==0 and c==0){
                ans+=a;
                cnt[1]++;
                break;
            }
            id=com(a,b,c);
            cnt[id]++;
            if(cnt[id]>n/2){
                cnt[id]--;
                id=com2(a,b,c);
                cnt[id]++;
                if(cnt[id]>n/2){
                    id=com3(a,b,c);
                    cnt[id]++;
                }

            }
            if(id==1){
                ans+=a;
            }
            if(id==2){
                ans+=b;
            }
            if(id==3){
                ans+=c;
            }
        }
        cout<<ans<<endl;
        memset(cnt,0,sizeof(cnt));
        ans=0;
    }
    return 0;
}
