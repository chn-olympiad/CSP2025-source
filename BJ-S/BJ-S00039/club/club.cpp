#include <iostream>
#include <cmath>
using namespace std;
freopen ("club.in","r",stdin);
freopen ("club.out","w",stdout);
int maxn(int a,int b){
    if(a>b){
        return a;
    }
    else if(a<b){
        return b;
    }
    else{

        return a;
    }


}
int n;
struct like{
    int s1;
    int s2;
    int s3;
}p[100000];
int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        int ss1=n/2;
        int ss2=n/2;
        int ss3=n/2;
        for(int i=1;i<=n;i++){
            cin>>p[i].s1;
            cin>>p[i].s2;
            cin>>p[i].s3;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(maxn(p[i].s1,p[i].s2)==p[i].s1&&maxn(p[i].s1,p[i].s3)==p[i].s1){
                if(ss1>0){
                    ss1--;
                    cnt+=p[i].s1;
                }
                else if(maxn(p[i].s2,p[i].s3)==p[i].s2){
                    if(ss2>0){
                        ss2--;
                        cnt+=p[i].s2;
                    }
                }
                else{
                    if(ss3>0){
                        ss3--;
                        cnt+=p[i].s3;
                    }
                }
            }
            else if(maxn(p[i].s2,p[i].s3)==p[i].s2){
                if(ss2>0){
                    ss2--;
                    cnt+=p[i].s2;
                }
                else if(ss3>0){
                    ss3--;
                    cnt+=p[i].s3;
                }
            }
            else{
                if(ss3>0){
                    ss3--;
                    cnt+=p[i].s3;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
