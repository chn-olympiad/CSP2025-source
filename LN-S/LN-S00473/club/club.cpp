#include<bits/stdc++.h>
using namespace std;
const int mxN=1e6+10;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int cs=0;cs<t;cs++){
        long long n=0,a[mxN][4],f[mxN][4],res,s[5],e[mxN][4];
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
                f[i][j]=a[i][j];
            }
            if(f[i][0]<f[i][1]){
                swap(f[i][0],f[i][1]);
                if(f[i][1]<f[i][2]){
                    swap(f[i][1],f[i][2]);
                    if(f[i][0]<f[i][1]){
                        swap(f[i][0],f[i][1]);
                        e[i][1]=3;
                        e[i][2]=2;
                        e[i][3]=1;
                    }
                    e[i][1]=2;
                    e[i][2]=3;
                    e[i][3]=1;
                }
                e[i][1]=2;
                e[i][2]=1;
                e[i][3]=3;

            }
            else if(f[i][0]<f[i][2]){
                swap(f[i][0],f[i][2]);
                swap(f[i][1],f[i][2]);
                e[i][1]=3;
                e[i][2]=1;
                e[i][3]=2;
            }
            else if(f[i][1]<f[i][2]){
                swap(f[i][1],f[i][2]);
                e[i][1]=1;
                e[i][2]=3;
                e[i][3]=2;
            }
            else{
                e[i][1]=1;
                e[i][2]=2;
                e[i][3]=3;
            }
        }
        for(int i=0;i<n;i++){
                for(int j=1;j<n-i-1;j++){
                    if(f[i][0]<f[i+j][0]){
                        swap(f[i][0],f[i+j][0]);
                        swap(f[i][1],f[i+j][1]);
                        swap(f[i][2],f[i+j][2]);
                        swap(e[i][1],e[i+j][1]);
                        swap(e[i][2],e[i+j][2]);
                        swap(e[i][3],e[i+j][3]);
                    }
                }

        }
        for(int i=0;i<n;i++){
            if(s[e[i][1]]<n/2){
                res+=f[i][0];
                s[e[i][1]]++;
            }else{
                res+=f[i][1];
                s[e[i][2]]++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
