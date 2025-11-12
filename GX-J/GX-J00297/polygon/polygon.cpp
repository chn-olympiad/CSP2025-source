#include<bits/stdc++.h>

using namespace std;

int n;
int l[5001];
int choice[5001],choice_ano[5001];
bool vis[5001];
int ans;

bool isPolygon(int sl[],int len){
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=sl[i];
    }
    if(sum>(sl[len-1]*2)){
        return true;
    }else return false;
}

void dfs(int num,int step,int now){
    if(step==num){
        //for(int i=0;i<num;i++){
        //    cout<<choice[i]<<" ";
        //}
        //cout<<endl;
        //cout<<"Result:"<<isPolygon(choice_ano,num)<<endl;
        if(isPolygon(choice_ano,num))ans++;
        return ;
    }
    for(int i=now;i<n;i++){
        if(vis[i]==0){
            if(l[i]>=choice[step-1]){
                //cout<<l[i]<<endl;
                choice[step]=l[i];
                choice_ano[step]=l[i];
                vis[i]=1;
                dfs(num,step+1,now+1);
                vis[i]=0;
            }

        }

    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l,l+n);
    for(int i=3;i<=n;i++){
        dfs(i,0,0);
    }
    cout<<ans;
    return 0;
}
