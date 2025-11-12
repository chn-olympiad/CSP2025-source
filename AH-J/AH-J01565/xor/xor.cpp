#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k;
int ans,x;
int a[500005];
string s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","W",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r,sum=0;
    while(l<=n){
        for(r=l;r<=n;r++){
            sum^=a[r];
            if(sum==k){
                //cout<<l<<" "<<r<<"\n";
                ans++;
                l=r+1;
                sum=0;
                break;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
