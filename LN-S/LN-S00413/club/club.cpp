#include<bits/stdc++.h>
using namespace std;
int  zu[5]={0,0,0,0,0};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,nn;
    cin>>t;
    long long ff=0;
    for(int i=1;i<=t;i++){
        long long n;
        cin>>n;
        nn=n/2;
        ff=0;
        for(int j=1;j<=n;j++){
            long long a=0,b=0,c=0;

            cin>>a>>b>>c;
            long long s=0;
            if(zu[1]<=nn&&zu[2]<=nn&&zu[3]<=nn){
                s=max(a,max(b,c));
                ff=ff+s;
                continue;
            }






            if(s==a){
                zu[1]++;
                if(zu[1]>nn){
                s=max(c,b);
                ff=ff+s;
                zu[1]--;
                if(s==c){
                    zu[3]++;

                }
                if(s==b){
                    zu[2]++;
                }
                continue;
                }
            }



            if(s==b){
                zu[2]++;
                if(zu[2]>nn){
                s=max(a,c);
                ff=ff+s;
                zu[2]--;
                if(s==a){
                    zu[1]++;

                }
                if(s==c){
                    zu[3]++;
                }
                continue;
               }
            }
            if(s==c){
                zu[3]++;
                if(zu[3]>nn){
                s=max(a,b);
                ff=ff+s;
                if(s==a){
                    zu[1]++;

                }
                if(s==b){
                    zu[2]++;
                }
                continue;
                }

            }

        }
        cout<<ff<<endl;
    }
    long long mm=0;
    return 0;
}

