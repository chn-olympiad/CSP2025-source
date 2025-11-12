#include<bits/stdc++.h>

using namespace std;

void d_4(){
    int q[4],w[4],e[4],r[4],t[4]={0,0,0,0};
    cin>>q[1]>>q[2]>>q[3]>>w[1]>>w[2]>>w[3]>>e[1]>>e[2]>>e[3]>>r[1]>>r[2]>>r[3];
    int ans=0;
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            for(int k=1;k<4;k++){
                for(int l=1;l<4;l++){
                    t[i]++,t[j]++,t[k]++,t[l]++;
                    if(t[1]<=2&&t[2]<=2&&t[3]<=2){
                        ans=max(ans,q[i]+w[j]+e[k]+r[l]);
                    }
                    t[i]--,t[j]--,t[k]--,t[l]--;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==2){
            int d1,d2,d3;
            int u1,u2,u3;
            cin>>d1>>d2>>d3>>u1>>u2>>u3;
            cout<<max(max(max(d1+u2,d1+u3),max(d2+u1,d2+u3)),max(d3+u1,d3+u2))<<endl;
        }
        if(n==4){
                d_4();
        }
    }
    return 0;
}
