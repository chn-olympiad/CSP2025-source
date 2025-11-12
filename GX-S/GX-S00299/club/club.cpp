#include<iostream>
#include<algorithm>

using namespace std;
int t,n,ans;
int a[5][100005],c[100005];
int b[5];
struct node{
    int xa,ya;
}d[100005];
void dfs(int x,int sum){
    if(x==n+1){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=3;i++){
        if(b[i]<n/2){
            b[i]++;
            dfs(x+1,sum+a[i][x]);
            b[i]--;
        }
    }
    return ;
}
bool cmp(node ta,node tb){
    return ta.xa+tb.ya<ta.ya+tb.xa;
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>a[1][i]>>a[2][i]>>a[3][i];
        }
        for(int i=1;i<=n;i++) d[i].xa=d[i].ya=0,c[i]=0;
        ans=0;
        if(n<=30) {
            b[1]=b[2]=b[3]=0;
            dfs(1,0);
            cout<<ans<<endl;
        }
        else{
            bool f=0;
            for(int i=1;i<=n;i++){
                if(a[2][i]!=0||a[3][i]!=0){
                    f=1;break;
                }
                c[i]=a[1][i];
            }
            if(f==0){
                int sum=0;
                sort(c+1,c+1+n);
                for(int i=n;i>=n-n/2+1;i--) sum+=c[i];
                cout<<sum<<"\n";
            }
            else {
                f=0;
                for(int i=1;i<=n;i++){
                    if(a[3][i]!=0){
                        f=1;break;
                    }
                    d[i].xa=a[1][i];
                    d[i].ya=a[2][i];
                }
                if(f==0){
                    sort(d+1,d+1+n,cmp);
                    /*for(int i=1;i<=n;i++){
                        cout<<d[i].xa<<" "<<d[i].ya<<"\n";
                    }*/
                    for(int i=1;i<=n/2;i++){
                        ans+=d[i].ya;
                    }
                    for(int i=n-n/2+1;i<=n;i++){
                        ans+=d[i].xa;
                    }
                    cout<<ans<<"\n";
                }
            }
        }
    }
    return 0;
}
