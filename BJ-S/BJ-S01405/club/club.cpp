#include<bits/stdc++.h>
using namespace std;
int a[4][100005],maxa[100005],maxid[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            maxa[i]=-1;
            for(int j=1;j<=3;j++){
                cin>>a[j][i];
                if(maxa[i]<a[j][i]){
                    maxa[i]=a[j][i];
                    maxid[i]=j;
                }
            }
        }
        int a1,b1,c1;
        a1=b1=c1=0;
        for(int i=1;i<=n;i++){
            if(maxid[i]==1) a1++;
            if(maxid[i]==2) b1++;
            if(maxid[i]==3) c1++;
        }
        for(int i=1;i<=n;i++){
            sum+=maxa[i];
        }
        //cout<<a1<<" "<<b1<<" "<<c1<<" ";
        if(a1*2<=n&&b1*2<=n&&c1*2<=n){
            cout<<sum<<endl;
            continue;
        }
        int k=max(a1,max(b1,c1));
        int l[k-n/2+1]={114515};
        int am[n+1];
        am[0]=114514;
        if(a1*2>n){
            for(int i=1;i<=n;i++){
                if(maxid[i]==1&&maxa[i]>=max(a[2][i],a[3][i])) am[i]=maxa[i]-max(a[2][i],a[3][i]);
                else am[i]=114514;
            }
            for(int i=1;i<=k-n/2+1;i++){
                int maxl=114513,maxlid=-1;
                for(int j=1;j<=n;j++){
                    if(am[j]<maxl){
                        maxl=am[j];
                        maxlid=j;
                    }
                }
                l[i]=maxl;
                am[maxlid]=114514;
                //cout<<"l"<<i<<"="<<l[i]<<" ";
            }
            //sort(am+1,am+n+1);
        }
        if(b1*2>n){
            for(int i=1;i<=n;i++){
                if(maxid[i]==2&&maxa[i]>=max(a[3][i],a[1][i])) am[i]=maxa[i]-max(a[3][i],a[1][i]);
                else am[i]=114514;
            }
            for(int i=1;i<=k-n/2+1;i++){
                int maxl=114513,maxlid=-1;
                for(int j=1;j<=n;j++){
                    if(am[j]<maxl){
                        maxl=am[j];
                        maxlid=j;
                    }
                }
                l[i]=maxl;
                am[maxlid]=114514;
                //cout<<"l"<<i<<"="<<l[i]<<" ";
            }
            //sort(am+1,am+n+1);
        }
        if(c1*2>n){
            for(int i=1;i<=n;i++){
                if(maxid[i]==3&&maxa[i]>=max(a[2][i],a[1][i])) am[i]=maxa[i]-max(a[2][i],a[1][i]);
                else am[i]=114514;
            }
            for(int i=1;i<=k-n/2+1;i++){
                int maxl=114513,maxlid=-1;
                for(int j=1;j<=n;j++){
                    if(am[j]<maxl){
                        maxl=am[j];
                        maxlid=j;
                    }
                }
                l[i]=maxl;
                am[maxlid]=114514;
                //cout<<"l"<<i<<"="<<l[i]<<" ";
            }
            //sort(am+1,am+n+1);
        }
        for(int i=1;i<=k-n/2;i++){
            sum-=l[i];
            //cout<<sum<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}
