#include<bits/stdc++.h>

using namespace std;
int n,s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }if(n>=3){
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int d=max(a[i],a[j]);
                for (int x=j+1;x<n;x++){
                    int d1=max(d,a[x]);
                    int z=a[i]+a[j]+a[x];
                    if (d1*2<z){
                        s++;
                    }
                }
            }
        }
    }else if(n<=4){
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int d=max(a[i],a[j]);
                for (int x=j+1;x<n;x++){
                    int d1=max(d,a[x]);
                    for (int y=x+1;y<n;y++){
                        int d2=max(d1,a[y]);
                        int z=a[i]+a[j]+a[x]+a[y];
                        if (d2*2<z){
                        s++;
                        }
                    }
                }
            }
        }
    }else if(n>=5){
        int d = max[a[0],a[1]];
        int d1 = max[d,a[2]];
        int d2 = max[d1,a[3]];
        int d3 = max[d2,a[4]];
        int z=a[0]+a[1]+a[2]+a[3]+a[4];
        if (d3*2<z){
            s++;
        }
    }
    cout<<s;
    return 0;
}
