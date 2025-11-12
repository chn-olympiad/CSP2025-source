#include<bits/stdc++.h>
using namespace std;
long long n,m,h=1,l=1,a[105];
bool cmp(long long q,long long e){return q>e;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    long long p=n*m;

    for(int i=1;i<=p;i++)cin>>a[i];
    long long f=a[1],k=0;
    sort(a+1,a+1+p,cmp);
    for(long long i=1;i<=p;i++){
        if(a[i]==f){
            k=i;break;
        }
    }

    int d=0;
    bool g=true;
    k--;
    //cout<<k;
    while(k!=0){
        k--;
        if(d==0){
            if(h==n){
                l++;
                d=1;
            }else h++;
        }else{
            if(g==false){
            if(h==1){
                l++;
                d=0;
            }else h--;
            }
        }
        g=false;
    }
    cout<<l<<" "<<h;
    return 0;

}
