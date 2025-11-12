#include <bits/stdc++.h>
using namespace std;

int T;
int n;
const int N=2e5+5;
int a[N][5];

int cnt[4],mx[N],id[N],scd[N],id2[N];
int b[N];

bool cmp(int a,int b){
    return a<b;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        for(int i=1;i<=3;i++) cnt[i]=0;
        cin>>n;
        int m=0;
        long long ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            mx[i]=0,scd[i]=0;
            for(int j=1;j<=3;j++){
                if(a[i][j]>=mx[i]) scd[i]=mx[i],mx[i]=a[i][j],id2[i]=id[i],id[i]=j;
                else if(a[i][j]>=scd[i]) scd[i]=a[i][j],id2[i]=j;
            }
            ans+=mx[i];
            cnt[id[i]]++;
        }
        int p=0;
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2) p=i;
        }
        //cout<<ans<<endl;
        if(p==0){
            cout<<ans<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                if(id[i]==p){
                    b[++m]=mx[i]-scd[i];
                    //cout<<mx[i]<<' '<<scd[i]<<endl;
                }
            }
            sort(b+1,b+m+1,cmp);
            for(int i=1;cnt[p]-i>=n/2;i++) ans-=b[i];
            cout<<ans<<endl;
        }
    }

    return 0;
}