#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,cnt1,cnt2,cnt3,a[N][4];
long long ans;
int b[N][4];
struct s{
    int idx,t,jian;
}t1[N],t2[N],t3[N];
bool cmp(s x,s y){
    return x.jian<y.jian;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cnt1=cnt2=cnt3=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2]){
                if(a[i][1]>a[i][3]){
                    b[i][1]=1;
                    if(a[i][2]>a[i][3]){
                        b[i][2]=2;
                        b[i][3]=3;
                    }else{
                        b[i][2]=3;
                        b[i][3]=2;
                    }
                }else{
                    b[i][1]=3;
                    if(a[i][2]>a[i][1]){
                        b[i][2]=2;
                        b[i][3]=1;
                    }else{
                        b[i][2]=1;
                        b[i][3]=2;
                    }
                }
            }else{
                if(a[i][3]>a[i][2]){
                    b[i][1]=3;
                    if(a[i][2]>a[i][1]){
                        b[i][2]=2;
                        b[i][3]=1;
                    }else{
                        b[i][3]=2;
                        b[i][2]=1;
                    }
                }else{
                    b[i][1]=2;
                    if(a[i][1]>a[i][3]){
                        b[i][2]=1;
                        b[i][3]=3;
                    }else{
                        b[i][3]=1;
                        b[i][2]=3;
                    }
                }
            }
            //cout<<b[i][1]<<" "<<b[i][2]<<" "<<b[i][3]<<"\n";
        }
        for(int i=1;i<=n;i++){
            if(b[i][1]==1){
                t1[++cnt1].t=a[i][1];
                t1[cnt1].idx=i;
                t1[cnt1].jian=a[i][b[i][2]]-a[i][b[i][1]];
            }else if(b[i][1]==2){
                t2[++cnt2].t=a[i][2];
                t2[cnt2].idx=i;
                t2[cnt2].jian=a[i][b[i][2]]-a[i][b[i][1]];
            }else{
                t3[++cnt3].t=a[i][3];
                t3[cnt3].idx=i;
                t3[cnt3].jian=a[i][b[i][2]]-a[i][b[i][1]];
            }
        }
        if(cnt1>n/2){
            sort(t1+1,t1+cnt1+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[t1[i].idx][1];
                //cout<<t1[i].idx<<":"<<1<<"\n";
            }
            for(int i=n/2+1;i<=cnt1;i++){
                ans+=a[t1[i].idx][b[t1[i].idx][2]];
                //cout<<t1[i].idx<<":"<<b[t1[i].idx][2]<<"\n";
            }
        }else{
            for(int i=1;i<=cnt1;i++){
                ans+=a[t1[i].idx][1];
                //cout<<t1[i].idx<<":"<<1<<"\n";
            }
        }
        if(cnt2>n/2){
            sort(t2+1,t2+cnt2+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[t2[i].idx][2];
                //cout<<t2[i].idx<<":"<<2<<"\n";
            }
            for(int i=n/2+1;i<=cnt2;i++){
                ans+=a[t2[i].idx][b[t2[i].idx][2]];
                //cout<<t2[i].idx<<":"<<b[t2[i].idx][2]<<"\n";
                //cout<<"{} "<<b[t2[i].idx][2]<<" "<<a[t2[i].idx][b[t2[i].idx][2]]<<"\n";
            }
            //cout<<b[2][2]<<"&&&"<<b[1][2]<<"\n";
        }else{
            for(int i=1;i<=cnt2;i++){
                ans+=a[t2[i].idx][2];
                //cout<<t2[i].idx<<":"<<2<<"\n";
            }
        }
        if(cnt3>n/2){
            sort(t3+1,t3+cnt3+1,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[t3[i].idx][3];
                //cout<<t3[i].idx<<":"<<3<<"\n";
            }
            for(int i=n/2+1;i<=cnt3;i++){
                ans+=a[t3[i].idx][b[t3[i].idx][2]];
                //cout<<t3[i].idx<<":"<<b[t3[i].idx][2]<<"\n";
            }
        }else{
            for(int i=1;i<=cnt3;i++){
                ans+=a[t3[i].idx][3];
                //cout<<t3[i].idx<<":"<<3<<"\n";
            }
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
