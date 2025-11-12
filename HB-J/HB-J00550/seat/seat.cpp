#include<bits/stdc++.h>
using namespace std;
int n,m,s1,c,r;
vector<int> scores;
int mp[109][109];
int cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        int in;
        cin>>in;
        scores.push_back(in);
        if(i==1){
            s1=in;
        }
    }
    sort(scores.begin(),scores.end(),greater<int>());
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(scores[cnt]==s1){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }else{
            for(int j=n;j>=1;j--){
                if(scores[cnt]==s1){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
    }
    return 0;
}
