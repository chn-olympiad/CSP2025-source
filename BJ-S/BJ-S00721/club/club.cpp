#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n,a[10010],b[10010],c[10010],s[10010],ans=0;
        bool f=true,g=true;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0||c[i]!=0)f=false;
            if(c[i]!=0)g=false;
            s[i]=max(max(a[i],b[i]),c[i]);
        }
        if(f){//特殊A
            sort(a+1,a+n+1);
            for(int i=n;i>n/2;i--){
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        }
        if(n==2){//1
            int t[3];
            for(int i=1;i<=2;i++){
                ans+=s[i];
                if(a[i]==s[i])t[i]=1;
                else if(b[i]==s[i])t[i]=2;
                else t[i]=3;
            }
            if(t[1]!=t[2]){
                cout<<ans<<endl;
                continue;
            }
            else{
                if(t[1]==1){//a
                    int d=max(b[1],c[1]);
                    int e=max(b[2],c[2]);
                    ans=max(ans-a[1]+d,ans-a[2]+e);
                }
                else if(t[1]==2){//b
                    int d=max(a[1],c[1]);
                    int e=max(a[2],c[2]);
                    ans=max(ans-b[1]+d,ans-b[2]+e);
                }
                else if(t[1]==3){//c
                    int d=max(b[1],a[1]);
                    int e=max(b[2],a[2]);
                    ans=max(ans-c[1]+d,ans-c[2]+e);
                }
            }
            cout<<ans<<endl;
            continue;
        }
        if(g){//特殊B weiwan
            int d=n/2,e=n/2;
            for(int i=1;i<=n;i++){
                if(a[i]>=b[i]&&d>0){
                    ans+=a[i];
                    d--;
                }
                else{
                    ans+=b[i];
                    e--;
                }
            }
            cout<<ans<<endl;
            continue;
        }
        else{
            for(int i=1;i<=n;i++){
                ans+=s[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
