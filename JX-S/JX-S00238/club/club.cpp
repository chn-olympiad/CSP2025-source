#include<iostream>
using namespace std;

int a,b,c,ta,tb,tc;
int t,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
            a=0,b=0,c=0,ta=0,tb=0,tc=0;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>ta>>tb>>tc;
            if(ta>tb&&ta>tc){
                if(a+1<=(n/2)){
                    ans+=ta;
                    a+=1;
                }
                else{
                    if(tb>tc&&b+1<=(n/2)){
                        ans+=tb;
                        b+=1;
                    }
                    else if(tc>tb&&c+1<=(n/2)){
                        ans+=tc;
                        c+=1;
                    }
                    else{
                        //break;
                    }
                }
            }
            else if(tb>tc&&tb>ta){
                if(b+1<=(n/2)){
                    ans+=tb;
                    b+=1;
                }
                else{
                    if(ta>tc&&a+1<=(n/2)){
                        ans+=ta;
                        a+=1;
                    }
                    else if(tc>ta&&c+1<=(n/2)){
                        ans+=tc;
                        c+=1;
                    }
                    else{
                        //break;
                    }
                }
            }
            else{
                if(c+1<=(n/2)){
                    ans+=tc;
                    c+=1;
                }
                else{
                    if(ta>tb&&a+1<=(n/2)){
                        ans+=ta;
                        a+=1;
                    }
                    else if(tb>ta&&b+1<=(n/2)){
                        ans+=tb;
                        b+=1;
                    }
                    else{
                        //break;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
