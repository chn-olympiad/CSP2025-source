#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n,a[100005][5],ans=0,yi=0,er=0,san=0;
        priority_queue<long long,vector<long long>,greater<long long > > q[4];
        cin>>n;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=3;j++){
                cin>>a[i][j];
            }
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                ans+=a[i][1];
                q[1].push(a[i][1]-max(a[i][2],a[i][3]));
                yi++;
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                ans+=a[i][2];
                q[2].push(a[i][2]-max(a[i][1],a[i][3]));
                er++;
            }
            else{
                ans+=a[i][3];
                q[3].push(a[i][3]-max(a[i][1],a[i][2]));
                san++;
            }
        }
        while(yi>n/2){
            ans-=q[1].top();
            q[1].pop();
            yi--;
        }
        while(er>n/2){
            ans-=q[2].top();
            q[2].pop();
            er--;
        }
        while(san>n/2){
            ans-=q[3].top();
            q[3].pop();
            san--;
        }
        cout<<ans<<endl;
    }
}
