#include<bits/stdc++.h>
using namespace std;

vector<int> a[4];
int sum[4];
long long ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        a[1].clear();sum[1]=0;
        a[2].clear();sum[2]=0;
        a[3].clear();sum[3]=0;
        ans=0;


        for(int i=1;i<=n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[1].push_back(x);
            a[2].push_back(y);
            a[3].push_back(z);
            if(x>=y&&x>=z){
                sum[1]++;
                ans+=x;
            }else if(y>=x&&y>=z){
                sum[2]++;
                ans+=y;
            }else{
                sum[3]++;
                ans+=z;
            }
        }

        if(sum[1]<=n/2&&sum[2]<=n/2&&sum[3]<=n/2){
            printf("%lld\n",ans);
        }else{
            if(sum[2]>n/2){
                swap(a[1],a[2]);
                swap(sum[1],sum[2]);
            }else if(sum[3]>n/2){
                swap(a[1],a[3]);
                swap(sum[1],sum[3]);
            }
            int cnt=sum[1]-n/2;
            vector<int> tmp;
            for(int i=0;i<n;i++){
                if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i])
                    tmp.push_back(max(a[2][i],a[3][i])-a[1][i]);
            }

            //for(int c:tmp)cerr<<c<<' ';cerr<<endl;

            sort(tmp.begin(),tmp.end());
            for(int i=1;i<=cnt;i++){
                ans+=tmp.back();
                tmp.pop_back();
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}