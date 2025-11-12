#include<bits/stdc++.h>
using namespace std;
int t,n,sum;
int a;
struct pp{
    int num;
    int a1,a2,a3;
}x[100005];
bool cmp(pp x,pp y){
    return x.a1>y.a1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++){
            cin>>x[i].a1>>x[i].a2>>x[i].a3;
            if(x[i].a1>x[i].a2) a++;
        }
        if(a>n/2){
            sort(x+1,x+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                sum+=x[i].a1;
            }
            for(int i=2/n+1;i<=n;i++){
                sum+=x[x[i].num].a2;
            }
        }
        cout<<sum<<endl;
    }
return 0;
}
