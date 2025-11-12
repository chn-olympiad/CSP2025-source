#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int sum=0,y=0,u=0,j=0,g,q,e,r,s,o;

        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a>b&&a>c){
                sum+=a;
                y++;

            }else if(b>a&&b>c){
                sum+=b;
                u++;

            }else if(c>a&&c>b){
                sum+=c;
                j++;

            }
            if(a>b&&b>c){
                g=a-b;
            }else if(a>c&&c>b){
                q=a-c;
            }else if(b>a&&a>c){
                e=b-a;
            }else if(b>c&&c>a){
                r=b-c;
            }else if(c>a&&a>b){
                s=c-a;
            }else if(c>b&&b>a){
                o=c-b;
            }
        }
        int h=n/2;
        if(h>=y&&h>=u&&h>=j){
            cout<<sum<<endl;
        }else if(h<y){

            if(g>=q){
                cout<<sum-q<<endl;
            }else if(q>=g){
                cout<<sum-g<<endl;
            }

        }else if(h<u){
            if(e>=r){
                cout<<sum-r<<endl;
            }else if(r>=e){
                cout<<sum-e<<endl;
            }
        }else if(h<j){
            if(s>=o){
                cout<<sum-o<<endl;
            }else if(o>=s){
                cout<<sum-s<<endl;
            }
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
