#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int u=0;u<t;u++){
        cin>>n;
        int a[n+5][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        int b[n+5],c[n+5],maxa=a[0][0],y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                if(maxa<a[i][j]){
                    maxa=a[i][j];
                    y=j;
                }
            }
            b[i]=maxa;
            c[i]=y;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;i<n;i++){
                if(b[j]>b[i]){
                    int l=b[i],r=c[i];
                    b[i]=b[j];
                    c[i]=c[j];
                    b[j]=l;
                    c[j]=r;
                }
            }
        }
        int s=0,f=0,k=0,e=0;
        for(int i=0;i<n;i++){
            if(c[i]==0){
                f++;
                if(f<=n/2)s+=b[i];
            }
            if(c[i]==1){
                k++;
                if(k<=n/2)s+=b[i];
            }
            if(c[i]==2){
                e++;
                if(e<=n/2)s+=b[i];
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
