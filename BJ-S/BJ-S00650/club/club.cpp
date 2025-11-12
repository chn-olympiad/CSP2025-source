#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > qa,qb,qc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        int x,y,z,a=0,b=0,c=0;
        long long ans=0;
        while(!qa.empty()) qa.pop();
        while(!qb.empty()) qb.pop();
        while(!qc.empty()) qc.pop();
        for(int i=1;i<=n;i++){
            cin>>x>>y>>z;
            if(x>=y&&x>=z){
                if(a<n/2){
                    ans+=x;
                    qa.push(x-max(y,z));
                    a++;
                }
                else if(x-max(y,z)<qa.top()){
                    ans+=max(y,z);
                }
                else{
                    ans-=qa.top();
                    qa.pop();
                    qa.push(x-max(y,z));
                    ans+=x;
                }
            }
            else if(y>=x&&y>=z){
                if(b<n/2){
                    ans+=y;
                    qb.push(y-max(x,z));
                    b++;
                }
                else if(y-max(x,z)<qb.top()){
                    ans+=max(x,z);
                }
                else{
                    ans-=qb.top();
                    qb.pop();
                    qb.push(y-max(x,z));
                    ans+=y;
                }
            }
            else if(z>=y&&z>=x){
                if(c<n/2){
                    ans+=z;
                    qc.push(z-max(y,x));
                    c++;
                }
                else if(z-max(y,x)<qc.top()){
                    ans+=max(x,y);
                }
                else{
                    ans-=qc.top();
                    qc.pop();
                    qc.push(z-max(x,y));
                    ans+=z;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
