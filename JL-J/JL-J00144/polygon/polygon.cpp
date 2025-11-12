#include<bits/stdc++.h>
using namespace std;
int a[10000];
int st[10000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    int ans=0;
    for(int i=1;i<=(1<<n)-1;i++){
        int k=i,boo=1;
        int cnt=0,l=1,s1=0;
        while(k){
            if(k%2){
                cnt+=a[l];
                st[l]=1;
                s1++;
            }
            l++;
            k/=2;
        }
        for(int i=1;i<=n;i++){
            if(st[i]){
                if(a[i]*2>=cnt){
                    boo=0;
                }
                st[i]=0;
            }
        }
        if(boo && s1>=3){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
