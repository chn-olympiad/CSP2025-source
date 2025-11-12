#include<iostream>
#include<fstream>
using namespace std;
int n,a[5001],u[5001],ans;
int maxn(int comp[]){
    int maxnn=0;
    for(int i=1;i<=sizeof(comp);i++){
        maxnn=max(maxnn,comp[i]);
    }
    return maxnn;
}
void wo(int s,int l){
    if(l==s){
        cout<<"I";
        int sum=0,lar;
        for(int i=1;i<=l;i++){
            sum+=u[i];
        }
        lar=maxn(u);
        lar*=2;
        if(lar>=sum){
            return;
        }
        else{
            ans++;
        }
    }
    for(int i=1;i<=n-s+l+1;i++){
            cout<<i<<" "<<n-s+l<<endl;
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(u[j]==i){
                flag=false;
            }
        }
        if(!flag){
            continue;
        }
        u[l]=a[i];
        wo(s,l+1);
        u[l+1]=0;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        sum=a[1]+a[2]+a[3];
        maxnn=maxn(a);
        if(maxnn*2>=sum){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    for(int i=3;i<=n;i++){
        wo(i,0);
    }
    cout<<ans;
    return 0;
}
