#include <bits/stdc++.h>
using namespace std;
long n,m,a[100000],c,j,w;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long i=1;i<=n*m;i++)cin>>a[i];
    c=a[1];
    for(long i=1;i<=n*m;i++){
        if(a[i]<a[i+1]){
            long x;
            x=a[i+1];
            a[i+1]=a[i];
            a[i]=x;
        }
    }
    for(long i=1;i<=n*m;i++){
        if(a[i]==c){
            long h=i;
            while(1){
                if(h<n && h!=0){
                    j+=1;
                    w=m+n-h;
                    while(w>n)w-=n;
                    break;
                }
                if(h<n && h==0){
                    if(j%2==0)w=1;
                    else w=n;
                    break;
                }
                h-=n;
                j+=1;
            }
            break;
        }
    }
    cout<<j<<" "<<w;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
