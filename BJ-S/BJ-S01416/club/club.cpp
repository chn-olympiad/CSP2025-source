#include<bits/stdc++.h>
using namespace std;
int p(int su,int a,int b,int c){
    if(su==a) return 1;
    if(su==b) return 2;
    if(su==c) return 3;
    if(su==a==b) return 12;
    if(su==a==c) return 13;
    if(su==b==c) return 23;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,sum=0,b,c,d,e=0,f=0,g=0;
    cin>>t;
    int n;
    for(int q=0;q<=t-1;q++){
        cin>>n;
        int a[n][3];
        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=2;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<=n-1;i++){
            b=a[i][0];
            c=a[i][1];
            d=a[i][2];
            int su=max(b,max(c,d));
            if(p(su,b,c,d)==1&&e<=n/2){
                sum+=b;
                e++;
            }else if(p(su,b,c,d)==2&&f<=n/2){
                sum+=c;
                f++;
            }else if(p(su,b,c,d)==3&&g<=n/2){
                sum+=d;
                g++;
            }else if(p(su,b,c,d)==12&&e<=n/2&&f<=n/2){
                if(e>f){
                    sum+=b;
                    e++;
                }else if(e<=f){
                    sum+=c;
                    f++;
                }else if(e==f==n/2){
                    sum+=d;
                    g++;
                }
            }else if(p(su,b,c,d)==13&&e<=n/2&&g<=n/2){
                if(e>g){
                    sum+=b;
                    e++;
                }else if(e<=g){
                    sum+=d;
                    g++;
                }else if(e==g==n/2){
                    sum+=c;
                    f++;
                }
            }else if(p(su,b,c,d)==23&&f<=n/2&&g<=n/2){
                if(f>g){
                    sum+=c;
                    f++;
                }else if(f<=g){
                    sum+=d;
                    g++;
                }else if(f==g==n/2){
                    sum+=b;
                    e++;
                }
            }
        }
        cout<<sum<<endl;
        sum=0;e=0;f=0;g=0;
    }
    return 0;
}