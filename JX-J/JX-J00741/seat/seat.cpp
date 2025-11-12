#include<bits/stdc++.h>
using namespace std;
const int N=205;
int cnt=0,ans=0;
int a[N];
int n,m,r,h,l;
bool cpp(int x,int y){
   return x>y;
}
int main(){
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            r=a[i];
        }
    }
    sort(a+1,a+n*m+1,cpp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
                if(i%n==0){
                    l=i/n;
                    if(l%2==0){
                        h=1;
                    }else{
                        h=m;
                    }
                    break;
                }

            l=i/n+1;
            if(l%2==0){
                h=m-i%n+1;
            }else{
                h=i%n;
            }
            break;
        }

    }
    cout<<l<<" "<<h<<endl;
   return 0;
}
