#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];
int n,b;
int cnt=0;
void dfs(int shunxu,int score1,int score2,int score3,int score){
    if(shunxu==b+1){
        cnt=max(cnt,score);
        //cout<<cnt<<endl;
        //return cnt;
    }
    if(score3<b/2) dfs(shunxu+1,score1,score2,score3+1,score+a[shunxu][3]);
    if(score2<b/2) dfs(shunxu+1,score1,score2+1,score3,score+a[shunxu][2]);
    if(score1<b/2) dfs(shunxu+1,score1+1,score2,score3,score+a[shunxu][1]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int cnt1=0,con=0;
        cin>>b;
        for(int i=1;i<=b;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        cnt=0;
        dfs(1,0,0,0,0);
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
