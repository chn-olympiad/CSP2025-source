#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
long long a[100006][10];
int d[6];
int main(){
    //freopen("clud.in","r",stdin);
    //freopen("clud.out","w",stdout);
    cin>>t;
    for(int time=1;time<=t;time++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        for(int i=1;i<=n;i++){
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                if(d[1]==n/2){
                    if(a[i][2]>a[i][3]){
                        if(d[2]==n/2){
                            d[3]+=a[i][3];
                        }else{
                            d[2]+=a[i][2];
                        }
                    }else{
                        if(d[3]==n/2){
                            d[2]+=a[i][2];
                        }else{
                            d[3]+=a[i][3];
                        }
                    }
                }
            }else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                if(d[2]==n/2){
                    if(a[i][1]>a[i][3]){
                        if(d[1]==n/2){
                            d[3]+=a[i][3];
                        }else{
                            d[1]+=a[i][1];
                        }
                    }else{
                        if(d[3]==n/2){
                            d[1]+=a[i][1];
                        }else{
                            d[3]+=a[i][3];
                        }
                    }
                }
            }else{
                if(d[3]==n/2){
                    if(a[i][1]>a[i][2]){
                        if(d[1]==n/2){
                            d[2]+=a[i][2];
                        }else{
                            d[1]+=a[i][1];
                        }
                    }else{
                        if(d[2]==n/2){
                            d[1]+=a[i][1];
                        }else{
                            d[2]+=a[i][2];
                        }
                    }
                }
            }
        }
        cout<<d[1]+d[3]+d[2]<<endl;
    }
    return 0;
}
