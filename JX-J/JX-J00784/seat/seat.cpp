#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
int n,m;
struct node{
    int score;
    int rank;
};
bool cmp(node a,node b){
    return a.score>b.score;
}
node a[N];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    int i;
    for(i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].rank=i;
    }

    int mine=a[1].score;
    sort(a+1,a+i+1,cmp);
    i=1;
    while(a[i].score!=mine){
        ++i;
    }
    int right=i;

    int c,r;
    c=(right-1)/n+1;
    if(c%2==1){
        r=right-(c-1)*n;
    }else{
        r=c*n+1-right;
    }
    cout<<c<<" "<<r;
    return 0;
}

//cout<<a[1].rank<<" "<<a[2].rank<<" "<<a[3].rank<<" "<<a[4].rank;
    //int left=0,right=n*m;
    //while(left<right){
    //    int mid=(left+right)/2;
     //   if(a[mid].score<mine)left=mid+1;
    //    if(a[mid].score>mine)right=mid+1;
    //}
