#include<bits/stdc++.h>
using namespace std;
int a[5005];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<3){
        cout<<0;
    }else{
        if(n==3){
            int he=a[1]+a[2]+a[0]-max(a[0],max(a[2],a[1]));
            if(max(a[0],max(a[2],a[1]))>he){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            for(int i=0;i<n;i++){
                if(a[i]!=1){
                    break;
                }
            }
            long long asna=1;
            for(int i=4;i<=n;i++){
                for(int j=4;j<=n;j++){
                    asna*=j;
                    asna%=998244353;
                }
            }
            cout<<asna;
        }

    }
    return 0;
    fclose(stdin);
    fclose(stdout);

}
