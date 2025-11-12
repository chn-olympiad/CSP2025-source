#include<bits/stdc++.h>
using namespace std;
int n,m;
struct pl{
    int xh,fs;
}a[105];
bool cmp(pl a,pl b){
    return a.fs>b.fs;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].fs;
        a[i].xh=i;
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].xh==1){
            if(i<=n){
                cout<<1<<' '<<i;
                break;
            }
            int h,l;
            if(i%n==0) h=i/n;
            else h=(i/n)+1;
            //cout<<h;
            if((h-1)%2==0){
                l=i-((h-1)*n);
            }
            else{
                l=i-((h-1)*n);
                l=n-l+1;
            }
            cout<<h<<' '<<l;
            break;
            //cout<<a[i].fs<<' '<<a[i].xh<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
