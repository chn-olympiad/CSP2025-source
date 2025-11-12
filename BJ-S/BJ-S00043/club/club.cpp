#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt1,cnt2,cnt3,ans;
long long a[100010][15],list1[100010],list2[100010],list3[100010];
struct node{
    long long maxx=-1,idx1,maxx2=-1,idx2,cha;
}r[100010];
bool cmp(long long c,long long d){
    return r[c].cha<r[d].cha;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>r[i].maxx){
                    r[i].maxx2=r[i].maxx;
                    r[i].idx2=r[i].idx1;
                    r[i].maxx=a[i][j];
                    r[i].idx1=j;
                }
                else if(a[i][j]>r[i].maxx2){
                    r[i].maxx2=a[i][j];
                    r[i].idx2=j;
                }
            }
            r[i].cha=r[i].maxx-r[i].maxx2;
        }
        for(long long i=1;i<=n;i++){
            if(r[i].idx1==1){
                list1[++cnt1]=i;
            }
            if(r[i].idx1==2){
                list2[++cnt2]=i;
            }
            if(r[i].idx1==3){
                list3[++cnt3]=i;
            }
            ans+=r[i].maxx;
        }
        if(cnt1>n/2){
            sort(list1+1,list1+cnt1+1,cmp);
            for(long long i=1;i<=cnt1-n/2;i++){
                ans-=r[list1[i]].cha;
            }
        }
        else if(cnt2>n/2){
            sort(list2+1,list2+cnt2+1,cmp);
            for(long long i=1;i<=cnt2-n/2;i++){
                ans-=r[list2[i]].cha;
            }
        }
        else if(cnt3>n/2){
            sort(list3+1,list3+cnt3+1,cmp);
            for(long long i=1;i<=cnt3-n/2;i++){
                ans-=r[list3[i]].cha;
            }
        }
        cout<<ans<<endl;
        for(long long i=1;i<=n;i++){
            list1[i]=0;
            list2[i]=0;
            list3[i]=0;
            r[i].maxx=-1;
            r[i].maxx2=-1;
            r[i].idx1=0;
            r[i].idx2=0;
            r[i].cha=0;
        }
        ans=0;
        cnt1=0;
        cnt2=0;
        cnt3=0;
    }
    return 0;
}
