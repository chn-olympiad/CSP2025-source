#include<bits/stdc++.h>
using namespace std;
int a[100000][3],b[100000];
int main(){
    int t,n,n1,n2,n3;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++){
        ans[i]=0;
        cin>>n;
        n1=0;
        n2=0;
        n3=0;
        for(int j=0;j<n;j++){
            for(int x=0;x<3;x++){
                cin>>a[j][x];
                if(a[j][0]>a[j][1]){
                    if(a[j][0]>a[j][2]){
                        n1++;
                        ans[i]=ans[i]+a[j][0];
                    }
                   else{
                       n3++;
                       ans[i]=ans[i]+a[j][2];
                   }
                }
                else{
                    if(a[j][1]>a[j][2]){
                        n2++;
                        ans[i]=ans[i]+a[j][1];
                    }
                    else{
                        n3++;
                        ans[i]=ans[i]+a[j][2];
                    }
                }
            }
        }
        if(n1>n/2){
            for(int j=0;j<n;j++){
                b[j]=a[j][0];
                sort(b,b+n);
            }
            for(int v=0;v<n/2;v++){
                ans[i]=ans[i]-a[v][0];
            }
            for(int x=n;x>n/2;x--){
                ans[i]=ans[i]+b[x-1];
            }
        }
          if(n2>n/2){
            for(int j=0;j<n;j++){
                b[j]=a[j][1];
                sort(b,b+n);
            }
            for(int v=0;v<n/2;v++){
                ans[i]=ans[i]-a[v][1];
            }
            for(int x=n;x>n/2;x--){
                ans[i]=ans[i]+b[x-1];
            }
        }
          if(n3>n/2){
            for(int j=0;j<n;j++){
                b[j]=a[j][2];
                sort(b,b+n);
            }
            for(int v=0;v<n/2;v++){
                ans[i]=ans[i]-a[v][2];
            }
            for(int x=n;x>n/2;x--){
                ans[i]=ans[i]+b[x-1];
            }
        }
    }
    for(int m=0;m<t;m++){
        cout<<ans[m]<<endl;
    }

    return 0;
}
