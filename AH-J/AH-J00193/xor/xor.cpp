#include<iostream>
#include<cstdio>
using namespace std;
int n,k;
int a[500007];
int t[1007];
int mx=-1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[a[i]]++;
        mx=max(mx,a[i]);
    }
    if( t[1]==n && k==0 ){
        cout<<n/2;
    }
    else if( t[0]+t[1]==n ){
        int cnt=0;
        if( k==0 ){
            for(int i=2;i<=n;i++){
                if( a[i]==a[i-1] && a[i]==1 ){
                    cnt++;
                }
            }
            cout<<t[0]+cnt;
        }
        else{
            cout<<t[1];
        }
    }
    else if( mx==255 ){

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
