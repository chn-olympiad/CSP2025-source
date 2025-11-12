#include<bits/stdc++.h>
using namespace std;
int t,n,r[5][100010],k[5];
long long ans,Max;
priority_queue<int> Ba;
priority_queue<int> Bb;
void dfs(int x){
    if(x==n+1){
        Max=max(Max,ans);
        return;
    }
    for(int i=1;i<=3;++i){
        if(k[i]<n/2){
            ans+=r[i][x];
            k[i]++;
            dfs(x+1);
            ans-=r[i][x];
            k[i]--;
        }
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int pdA=0,pdB=0,pdC=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=3;++j){
                cin>>r[j][i];
            }
            if(r[2][i]!=0||r[3][i]!=0){
                pdA=1;
            }
            if(r[3][i]!=0){
                pdB=1;
            }
        }
        if(pdA==0){
            long long ansA;
            sort(r[1]+1,r[1]+n+1);
            ansA=0;
            for(int i=1;i<=n/2;++i){
                ansA+=r[1][i];
            }
            cout<<ansA<<endl;
            continue;
        }
        if(pdB==0){
            while(!Ba.empty()) Ba.pop();
            while(!Bb.empty()) Bb.pop();
            long long ansB=0;
            int ra=0,rb=0;
            for(int i=1;i<=n;++i){
                if(r[1][i]>r[2][i]){
                    if(ra<n/2){
                        ra++;
                        Ba.push(1e6-max(r[1][i],r[2][i])+min(r[1][i],r[2][i]));
                        ansB+=r[1][i];
                    }
                    else if(Ba.top()>1e6-max(r[1][i],r[2][i])+min(r[1][i],r[2][i])){
                        ansB-=(1e6-Ba.top());
                        ansB+=r[1][i];
                        Ba.pop();
                        Ba.push(1e6-max(r[1][i],r[2][i])+min(r[1][i],r[2][i]));
                    }
                    else{
                        ansB+=r[2][i];
                    }
                }
                else{
                    if(rb<n/2){
                        rb++;
                        Bb.push(1e6-max(r[1][i],r[2][i])+min(r[1][i],r[2][i]));
                        ansB+=r[2][i];
                    }
                    else if(Bb.top()>1e6-max(r[1][i],r[2][i])+min(r[1][i],r[2][i])){
                        ansB-=(1e6-Bb.top());
                        ansB+=r[2][i];
                        Bb.pop();
                        Bb.push(1e6-max(r[1][i],r[2][i])+min(r[1][i],r[2][i]));
                    }
                    else{
                        ansB+=r[1][i];
                    }
                }
            }
            cout<<ansB<<endl;
            continue;
        }
        k[1]=0;
        k[2]=0;
        k[3]=0;
        ans=0;
        Max=0;
        dfs(1);
        cout<<Max<<endl;
    }
    return 0;
}
