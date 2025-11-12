//Finished at 16:14
#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[4],ans;
#define int long long
struct Node{
    int num[4],delta;
}a[100010];
bool cmp(Node x,Node y){
    return x.delta<y.delta;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        ans=0;for(int i=1;i<=3;i++)cnt[i]=0;
        cin>>n;
        for(int i=1;i<=n;i++)a[i].delta=0x7fffffff;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++)
                cin>>a[i].num[j];
            int max_no,max_val=-1;
            for(int j=1;j<=3;j++)
                if(max_val<a[i].num[j]){
                    max_val=a[i].num[j];
                    max_no=j;
                }
            cnt[max_no]++;
            ans+=max_val;
        }
        int flag=0;
        for(int i=1;i<=3;i++)
            if(cnt[i]>n/2)
                flag=i;
        if(flag==0){//No remove,end directly.
            cout<<ans<<endl;
            continue;
        }
        //There is a group which has more than n/2 people.

        for(int i=1;i<=n;i++){//to give delta
            int max_no,max_val=-1;
            for(int j=1;j<=3;j++)
                if(max_val<a[i].num[j]){
                    max_val=a[i].num[j];
                    max_no=j;
                }
            if(max_no==flag){
                int t1,t2;
                if(max_no==1){t1=2;t2=3;}
                if(max_no==2){t1=1;t2=3;}
                if(max_no==3){t1=1;t2=2;}
                a[i].delta=max_val-max(a[i].num[t1],a[i].num[t2]);
                //cout<<a[i].delta<<' ';
            }
        }
        /*cout<<endl;
        for(int i=1;i<=n;i++)cout<<a[i].delta<<' ';
        cout<<endl;*/
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=cnt[flag]-n/2;i++){
            ans-=a[i].delta;//cout<<a[i].delta<<' ';
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
