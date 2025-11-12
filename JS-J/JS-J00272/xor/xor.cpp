#include<bits/stdc++.h>
using namespace std;
int a[2005],b[2005],ans,num[2005][2005];
int n,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=b[i-1]^a[i];
    }
    /*for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }*/
    //cout<<endl;
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=x;j<=i;j++){
            int y;
            if(j!=0)y=b[i]^b[j-1];
            else y=b[i];
            if(i==j){
                if(a[i]==k){
                    ans++;//cout<<i<<" "<<j<<y<<endl;
                    x=j+1;
                    break;
                }
                //cout<<i<<" "<<j<<endl;
            }else{
                if(y==k){
                    ans++;//cout<<i<<" "<<j<<y<<endl;
                    x=j+1;
                    break;
                }
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*9 4 1 4 5 4 1 0 2 3 5*/
