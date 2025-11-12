#include <bits/stdc++.h>
using namespace std;
long long n,m,a[125];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
        cin>>n>>m;
    for(int i=1;i<=n*m;i++){

            cin>>a[i];

    }
    long long cnt=a[1],h=0,l=1;

    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(l%2==1){
            h++;
        }else{
            h--;
        }
        if(h>n||h<=0){
            if(l%2==1){
                h=n;
            }else{
                h=1;
            }
            l++;
        }
        if(l%2==1){
            if(a[(l-1)*n+h]==cnt){
                cout<<l<<' '<<h;
                break;
            }
        }else{
            if(a[l*n-h+1]==cnt){
                cout<<l<<' '<<h;
                break;
            }


        }


    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}
