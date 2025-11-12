#include <bits/stdc++.h>
using namespace std;
struct node{
    long long s;
}a[20010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    long long n;
    cin>>t>>n;
    while(t--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i].s;
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            if(n%2==0){
                long long score=0;
                score=a[i].s+a[i++].s;
                sum++;
                if(sum<=n/2){
                    cout<<score<<endl;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }
    return 0;
}
