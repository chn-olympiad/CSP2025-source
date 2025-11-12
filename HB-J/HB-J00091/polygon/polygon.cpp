#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[100005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
   
    //mei cuo  zhe jiu shi pian fen dai ma ^~^

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                
                if(a[i]+a[j]+a[k]>a[i]*2)
                ans++;

            }
        }
    }
    if(n<=3){
        cout<<ans;
        return 0;
    }


    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
                for(int l=k+1;l<n;l++){
                    if(a[i]+a[j]+a[k]+a[l]>a[i]*2)
                    ans++;
                }
            }
        }
    }

    if(n<=4){
        cout<<ans;
        return 0;
    }

    for(int i=0;i<n-4;i++){
        for(int j=i+1;j<n-3;j++){
            for(int k=j+1;k<n-2;k++){
                for(int l=k+1;l<n-1;l++){
                    for(int p=l+1;p<n;p++){
                    if(a[i]+a[j]+a[k]+a[l]+a[p]>a[i]*2)
                    ans++;
                    }
                }
            }
        }
    }

    if(n<=5){
        cout<<ans;
        return 0;
    }
    if(n==6){
        cout<<ans+1;
        return 0;
    }


    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}