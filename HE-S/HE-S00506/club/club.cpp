#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t1=0,t2=0,t3=0;
    int n,b[10001],x[10001],y[10001],z[10001],s=0,ans[10001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i];
        for(int j=0;j<b[i];j++){
            cin>>x[j]>>y[j]>>z[j];
        }
    }
    for(int i=0;i<n;i++){
            ans[i]=0;
        for(int j=0;j<b[i];j++){
            if(x[j]>y[j]&&y[j]>z[j]){
                s+=x[j];
            }else if(y[j]>x[j]&&y[j]>z[j]){
                s+=y[j];
            }else{
                s+=z[j];
            }
        }
        cout<<s;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
