#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
void Q(){
    priority_queue<long long>p[3];
    long long n,a[N][5]={0},ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m1=3,m2=3;
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            if(a[i][m1]<=a[i][j]){
                m2=m1,m1=j;
            }else if(a[i][m2]<a[i][j]){
                m2=j;
            }
        }
        //cout<<m2<<" "<<m1<<endl;
        p[m1].push(a[i][m2]-a[i][m1]);
        ans+=a[i][m1];
        //cout<<p[m1].size()<<endl;
        if(p[m1].size()>n/2){
            int t=p[m1].top();
            //cout<<t<<endl;
            p[m1].pop();
            ans+=t;
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;

}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        Q();
    }
    return 0;
}
