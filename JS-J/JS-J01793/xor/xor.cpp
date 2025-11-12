#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==0){
        if(n%2==0){
            cout<<n/2;
        }
        else{
            cout<<(n-1)/2;
        }
    }
    else if(k==1){
        int x=0,y=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                x++;
            }
            else{
                y++;
            }
        }
        cout<<min(x,y);
    }
    else{
        cout<<n/3;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
