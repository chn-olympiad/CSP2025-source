#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b=0;
int dfs(int x,int y,int z){
    if(z<3){
        return 0;
    }
    for(int i=x;i<n;i++){
        if(a[i]<y){
            b+=1;
            dfs(x,y-a[i],z-1);
        }
    }return 0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]>a[j]){
                int q=a[i];
                a[i]=a[j];
                a[j]=q;
            }
        }
    }int w=0;
    while(w<n-2){
        int r=3;
        int p=a[w]+a[w+1]+a[w+2];
        for(int i=w+2;i<n;i++){
            if(p>2*a[i]){
                b+=1;
                dfs(w,p-2*a[i],r);
            }
            p+=a[i];
            r+=1;
        }
    }
    cout << b%998 << endl;
    return 0;
}
