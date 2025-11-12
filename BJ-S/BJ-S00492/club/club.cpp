#include<bits/stdc++.h>
using namespace std;
int t,gp[100010],v[100010][5];
priority_queue<int> pq;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(int zz=1;zz<=t;zz++){
        int n;
        cin>>n;
        int ans=0;
        int cnta=0,cntb=0,cntc=0;
        for(int i=1;i<=n;i++){
            cin>>v[i][1]>>v[i][2]>>v[i][3];
            if(v[i][1]>max(v[i][2],v[i][3])){
                gp[i]=1;
                cnta++;
                ans+=v[i][1];
            }else if(v[i][2]>max(v[i][1],v[i][3])){
                gp[i]=2;
                cntb++;
                ans+=v[i][2];
            }else if(v[i][3]>max(v[i][1],v[i][2])){
                gp[i]=3;
                cntc++;
                ans+=v[i][3];
            }else{
                gp[i]=0;
                ans+=max(v[i][1],max(v[i][2],v[i][3]));
            }
        }
        //sort(v+1,v+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(cnta>n/2 && gp[i]==1){
                pq.push(v[i][1]-max(v[i][2],v[i][3]));
                if(pq.size()>cnta-n/2){
                    pq.pop();
                }
            }else if(cntb>n/2 && gp[i]==2){
                pq.push(v[i][2]-max(v[i][1],v[i][3]));
                if(pq.size()>cntb-n/2){
                    pq.pop();
                }
            }else if(cntc>n/2 && gp[i]==3){
                pq.push(v[i][3]-max(v[i][1],v[i][2]));
                if(pq.size()>cntc-n/2){
                    pq.pop();
                }
            }
            
        }
        while(!pq.empty()){
            int p=pq.top();
            pq.pop();
            ans-=p;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
//g++ club.cpp -o a -O2 -std=c++14 -static -Wall -Wextra