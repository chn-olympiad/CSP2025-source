#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+7];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int b=0,c=0;
    for(int i=1;i<=n;i++){
            c+=a[i];
        for(int j=i+1;j<=n;j++){
            if(c^a[j]==m){
                b+=1;
                i=j+1;
            }
        }
    }
    cout<<b-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
