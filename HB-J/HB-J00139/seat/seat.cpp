#include<bits/stdc++.h>
using namespace std;
double m,n;
int a[121],p=1;
int main(){
    freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i!=1){
            if(a[i]>a[1])p++;
        }
    }
    double ans_m=double(p)/n;
    int ans_n=p%int(n);
    if(ans_n==0)ans_n=n;
    if(int((ceil(ans_m)))%2==0){
        ans_n=n-ans_n+1;
    }
    cout<<ceil(ans_m)<<" "<<ans_n;
    fclose(stdin);fclose(stdout);
    return 0;
}