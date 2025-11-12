#include<bits/stdc++.h>
using namespace std;
int a[108];
int b[108][108];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int x,y;
    cin>>x>>y;
    int n=x*y;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+n+1);
    int xx=1,yy=1,zzz=0;
    for(int i=n;i>=1;i--){
        b[xx][yy]=a[i];
        if(a[i]==s){
            cout<<yy<<" "<<xx;
            break;
        }
        if(zzz==0){
            xx++;
        }
        else if(zzz==1){
            xx--;
        }
        if(xx>x){
            xx--;
            yy++;
            zzz=1;
        }
        else if(xx<1){
            xx++;
            yy++;
            zzz=0;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
