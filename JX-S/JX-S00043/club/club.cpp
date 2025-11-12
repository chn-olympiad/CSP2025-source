#include<bits/stdc++.h>
using namespace std;

struct togood{
    int n,num,worker_num;
};
priority_queue <togood> pr_q;
int l[100010][4];//l[i][j] the i to j good %
int t_x[100010];
int club_num[4];
bool operator<(togood a,togood b){
    return a.n<b.n;
}

int t,n;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(l,0,sizeof(l));
        memset(t_x,0,sizeof(t_x));
        memset(club_num,0,sizeof(club_num));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%d",&l[i][j]);
                togood a;
                a.n=l[i][j],a.num=j,a.worker_num=i;
                pr_q.push(a);

            }
        }
        int ans=0;
        while(!pr_q.empty()){
            int nc=pr_q.top().n,num=pr_q.top().num,work_num=pr_q.top().worker_num;
            //cout << nc <<' '<<num<<' '<<work_num<<endl;
            if(!t_x[work_num]&&club_num[num]+1<=n/2) ans+=nc,t_x[work_num]=1,club_num[num]++;
            pr_q.pop();
        }/*
        while(!pr_q.empty()){
            printf("%d ",pr_q.top().n);
            pr_q.pop();
        }*/
        cout << ans <<endl;
    }
    return 0;
}
