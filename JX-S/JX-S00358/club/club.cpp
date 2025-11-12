#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int T,n,cnt;
long long int maxn=0,maxd[4];
int d[N][4],a[N];
void dfs(int m,int x,int y,int z,int ans){
    if(x>cnt||y>cnt||z>cnt) return ;
    if(m==n){
        if(ans>maxn) maxn=ans;
        return ;
    }
    dfs(m+1,x+1,y,z,ans+d[m+1][1]);
    dfs(m+1,x,y+1,z,ans+d[m+1][2]);
    dfs(m+1,x,y,z+1,ans+d[m+1][3]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        cnt=n/2;
        maxn=0;
        maxd[1]=0,maxd[2]=0,maxd[3]=0;
        for(int i=1;i<=n;i++){
            cin>>d[i][1]>>d[i][2]>>d[i][3];
            if(d[i][1]>maxd[1]) maxd[1]=d[i][1];
            if(d[i][2]>maxd[2]) maxd[2]=d[i][2];
            if(d[i][3]>maxd[3]) maxd[3]=d[i][3];
        }
        if(n<=10){
            dfs(0,0,0,0,0);
            cout<<maxn<<endl;
        }
        else if(maxd[1]==0&&maxd[2]==0){
            for(int i=1;i<=n;i++){
                a[i]=d[i][3];
            }
            sort(a+1,a+n+1);
            for(int i=n;i>cnt;i--) maxn+=a[i];
            cout<<maxn<<endl;
        }
        else if(maxd[1]==0&&maxd[3]==0){
            for(int i=1;i<=n;i++){
                a[i]=d[i][2];
            }
            sort(a+1,a+n+1);
            for(int i=n;i>cnt;i--) maxn+=a[i];
            cout<<maxn<<endl;
        }
        else if(maxd[2]==0&&maxd[3]==0){
            for(int i=1;i<=n;i++){
                a[i]=d[i][1];
            }
            sort(a+1,a+n+1);
            for(int i=n;i>cnt;i--) maxn+=a[i];
            cout<<maxn<<endl;
        }
        else if(maxd[3]==0){
            int cnt1=0,cnt2=0,cha[N],sm[N],cont;
            for(int i=1;i<=n;i++){
                if(d[i][1]>d[i][2]){
                    cnt1++;
                    sm[i]=d[i][1];
                    cha[i]=d[i][1]-d[i][2];
                }
                else{
                    cnt2++;
                    sm[i]=d[i][2];
                    cha[i]=d[i][2]-d[i][1];
                }
            }
            for(int i=1;i<=n;i++) maxn+=sm[i];
            if(cnt1==cnt&&cnt2==cnt) cout<<maxn<<endl;
            else{
                if(cnt1>cnt2) cont=cnt1-cnt;
                else cont=cnt2-cnt;
                sort(cha+1,cha+n+1);
                for(int i=1;i<=cont;i++) maxn-=cha[i];
                cout<<maxn<<endl;
            }
        }
    }
    return 0;
}
