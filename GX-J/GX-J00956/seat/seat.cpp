#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[3],score[200],ming,p,l,r,mid;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    p=n*m;
    for(int i=1;i<=p;i++){
        cin>>score[i];
    }
    ming=score[1];
    sort(score+1,score+1+p);
    l=1,r=p,mid=(l+r)/2;
    while(score[mid]!=ming){
        if(score[mid]>ming){
            r=mid;
            mid=(l+r)/2;
        }
        else{
            l=mid;
            mid=(l+r)/2;
        }
    }
    mid=p-mid+1;
    if(mid%n==0){
        ans[0]=mid/n;
        if(ans[0]%2==0)ans[1]=1;
        else ans[1]=n;
    }
    else{
        ans[0]=mid/n+1;
        if(ans[0]%2==0)ans[1]=n-mid%n+1;
        else ans[1]=mid%n;
    }
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
