#include<bits/stdc++.h>
using namespace std;
int t,ans,n;
int a[100010][4],ma[100010];
int club_max[4],cnt[4],club_ans;
bool num[100010];
int find_max(int num){
    int ans=-1e9;
    for(int i=1;i<=3;i++){
        ans=max(ans,a[num][i]);
    }
    return ans;
}
int find_idk(int x,int xmax){
    int xmax_idk=0;
    for(int i=1;i<=3;i++){
        if(a[x][i]==xmax){
            xmax_idk=i;
            break;
        }
    }
    return xmax_idk;
}
void init(){
    club_ans=0;
    for(int i=1;i<=n;i++){
        ma[i]=0;
        num[i]=false;
        for(int j=1;j<=3;j++){
            a[i][j]=0;
        }
    }
    for(int j=1;j<=3;j++){
        club_max[j]=0;
        cnt[j]=0;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        init();
        int mid=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        for(int j=1;j<=3;j++){
            for(int i=1;i<=n;i++){
                club_max[j]=max(club_max[j],a[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(num[i]||cnt[j]>=mid)continue;
                if(a[i][j]==club_max[j]){
                    cnt[j]++;
                    num[i]=true;
                    club_ans+=a[i][j];
                    a[i][j]=0;
                }
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(!num[i])q.push(i);
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            int xmax=find_max(x);
            int xidk=find_idk(x,xmax);
            if(cnt[xidk]<mid){
                cnt[xidk]++;
                club_ans+=xmax;
            }
            else{
                a[x][xidk]=0;
                q.push(x);
            }
        }
        cout<<club_ans<<endl;
    }
    return 0;
}
