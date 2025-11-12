#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
LL t,n;
struct Node{

    LL f;//first
    LL s;
    LL t;
}a[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        LL sum;
        for(int i=1;i<=n;i++){//i ge ren
            cin>>a[i].f>>a[i].s>>a[i].t;
        }
        bool AAA=0,BBB=0;
        for(int i=1;i<=n;i++){
            if(a[i].f!=0&&a[i].s==0&&a[i].t==0) AAA=1;
            if(a[i].f!=0&&a[i].s!=0&&a[i].t==0) BBB=1;
        }
        if(AAA){
            for(int i=1;i<=n;i++){
                sum+=a[i].f;
            }
        }
        if(BBB){
            for(int i=1;i<=n;i++){
                    int fc=0,sc=0;
                if(a[i].f>a[i].s&&fc<n/2||sc>=n/2){
                    sum+=a[i].f;
                    fc++;
                }else{
                    sum+=a[i].s;
                    sc++;
                }
            }
        }

        cout<<sum<<'\n';
    }
    return 0;
}
