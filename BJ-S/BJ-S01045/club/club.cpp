#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int a[N][3],wco[3][N],cnt[3],js[N];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,ans=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=max(a[i][1],a[i][2])){
                wco[0][cnt[0]]=i;
                cnt[0]++;
                ans+=a[i][0];
            }
            else if(a[i][1]>=max(a[i][0],a[i][2])){
                wco[1][cnt[1]]=i;
                cnt[1]++;
                ans+=a[i][1];
            }
            else{
                wco[2][cnt[2]]=i;
                cnt[2]++;
                ans+=a[i][2];
            }
        }
        if(cnt[0]>n/2){
            for(int i=0;i<cnt[0];i++){
                int zd=max(max(a[wco[0][i]][0],a[wco[0][i]][1]),a[wco[0][i]][2]);
                int cd=max(max(min(a[wco[0][i]][0],a[wco[0][i]][1]),min(a[wco[0][i]][0],a[wco[0][i]][2])),min(a[wco[0][i]][2],a[wco[0][i]][1]));
                js[i]=zd-cd;
            }
            sort(js,js+cnt[0]);
            for(int i=0;cnt[0]>n/2;i++){
                ans-=js[i];
                cnt[0]--;
            }
            for(int i=0;i<cnt[0];i++)js[i]=0;
        }
        else if(cnt[1]>n/2){
            for(int i=0;i<cnt[1];i++){
                int zd=max(max(a[wco[1][i]][0],a[wco[1][i]][1]),a[wco[1][i]][2]);
                int cd=max(max(min(a[wco[1][i]][0],a[wco[1][i]][1]),min(a[wco[1][i]][0],a[wco[1][i]][2])),min(a[wco[1][i]][2],a[wco[1][i]][1]));
                js[i]=zd-cd;
            }
            sort(js,js+cnt[1]);
            for(int i=0;cnt[1]>n/2;i++){
                ans-=js[i];
                cnt[1]--;
            }
            for(int i=0;i<cnt[1];i++)js[i]=0;
        }
        else if(cnt[2]>n/2){
            for(int i=0;i<cnt[2];i++){
                int zd=max(max(a[wco[2][i]][0],a[wco[2][i]][1]),a[wco[2][i]][2]);
                int cd=max(max(min(a[wco[2][i]][0],a[wco[2][i]][1]),min(a[wco[2][i]][0],a[wco[2][i]][2])),min(a[wco[2][i]][2],a[wco[2][i]][1]));
                js[i]=zd-cd;
            }
            sort(js,js+cnt[2]);
            for(int i=0;cnt[2]>n/2;i++){
                ans-=js[i];
                cnt[2]--;
            }
            for(int i=0;i<cnt[2];i++)js[i]=0;
        }
        cout<<ans<<endl;
        for(int i=0;i<cnt[0];i++)wco[0][i]=0;
        for(int i=0;i<cnt[1];i++)wco[1][i]=0;
        for(int i=0;i<cnt[2];i++)wco[2][i]=0;
        cnt[0]=0;
        cnt[1]=0;
        cnt[2]=0;
    }
    return 0;
}
