#include <iostream>
using namespace std;
long long n,a[5001],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int l=1,r=3;
    long long Lmax,Lsum;
    while(l<=r-2){
        Lmax=-1,Lsum=0;
        for(int i=l;i<=r;i++){
            if(a[i]>Lmax){
                Lsum+=Lmax;
                Lmax=a[i];
            }else{
                Lsum+=a[i];
            }
        }
        if(Lmax<Lsum) cnt++;
        r++;
        if(r==n) l++;
    }
    cout << cnt;
    return 0;
}
