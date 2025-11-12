#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int like[N][4],fir[N],sec[N];
int n;
long long gt_n_a(int x){
    int cnt=0;
    int na[N];
    for(int i=1;i<=n;i++){
        if(fir[i]==x){
            na[++cnt]=like[i][fir[i]]-like[i][sec[i]];
        }
    }
    sort(na+1,na+1+cnt);
    //for(int i=1;i<=cnt;i++)cout<<na[i]<<" ";
    //cout<<endl;
    long long res=0;
    for(int i=1;i<=cnt-n/2;i++)res+=na[i];
    return res;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            int fa=0,sa=0;
            like[i][0]=-1;
            for(int j=1;j<=3;j++){
                scanf("%d",&x);
                like[i][j]=x;
                if(x>=like[i][fa]){
                    sa=fa;
                    fa=j;
                }else if(x>=like[i][sa]){
                    sa=j;
                }
            }
            fir[i]=fa;
            sec[i]=sa;
        }
        //for(int i=1;i<=n;i++)printf("%d %d\n",fir[i],sec[i]);
        long long ans=0;
        int cnt[4]={0,0,0,0};
        for(int i=1;i<=n;i++)ans+=like[i][fir[i]],cnt[fir[i]]++;
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2){
                ans-=gt_n_a(i);
            }
        }
        printf("%lld\n",ans);
    }
	return 0;
}
