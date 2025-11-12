#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n,m,sum=0,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]^a[i];
        }
    a[0]=0;
    for(int i=0;i<n;i){
        for(int j=i+1;j<=n;j++){
            if(a[i]^a[j]==m){
                sum++;
                b=j;
                break;
            }
        }
        i=b;
    }
    cout<<sum;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
