#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    int k=0;
    int cnt=1;
    for(int i=0;i<n*m;i++){
        int x;cin>>x;
        a.push_back(x);
        if(i==0) k=a[0];
        else{
            if(a[i]>k) cnt++;
        }
    }
    int ans1=ceil(cnt/double(n));//lie
    int ans2;
    if(ans1%2==1){
        ans2=cnt-(ans1-1)*n;
    }
    else{
        ans2=n-(cnt-(ans1-1)*n)+1;
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}
