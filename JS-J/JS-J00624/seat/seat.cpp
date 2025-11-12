#include<bits/stdc++.h>
#define I using
#define AK namespace
#define CSP std;
I AK CSP
#define ll long long
int n,m,ansp;
int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int ff=m*n;
    int score[ff];
    for(int i=0;i<n*m;i++){
        cin>>score[i];
    }
    int x=score[0];
    sort(score,score+ff+1);
    int l=0,r=n*m-1;
    while(l<r){
        int mid=l+(l+r)/2;
        if(score[mid]==x){
            ansp=mid;
            break;
        }
        if(score[mid]>x){
            r=mid+1;
        }
        if(score[mid]<x){
            l=mid;
        }
    }
    int ans=ff-ansp+1;
    if(ans%n==0)
        cout<<ans/n<<" ";
    else
        cout<<ans/n+1<<" ";
    int c;
    if(ans/n)
        c=n-(ans%n);
    if(ans/n==0)
        c=ans%n;
    cout<<c;
    return 0;
}
