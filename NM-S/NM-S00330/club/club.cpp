#include<bits/stdc++.h>
using namespace std;
#define int long long
struct abcd{
    int aa[4],m[4],b[4];
};
int t,n,ans;
bool cmp1(abcd x,abcd y){
        if (x.b[2]==0&&y.b[2]!=0) return 1;
        else if (x.b[2]!=0&&y.b[2]==0) return 0;
        else if (x.b[1]>y.b[1]) return 1;
        else if (x.b[1]<y.b[1]) return 0;
        else if (x.b[1]==y.b[1]){
            if (x.b[3]==0&&y.b[3]!=0) return 1;
            else if (x.b[3]!=0&&y.b[3]==0) return 0;
            else if (x.b[2]>y.b[2]) return 1;
            else if (x.b[2]<y.b[2]) return 0;
            else if (x.b[2]==y.b[2]){
                if (x.b[3]>y.b[3]) return 1;
                else if (x.b[3]<y.b[3]) return 0;
            }
        }

}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for (int i=1;i<=t;i++){
        cin>>n;
        abcd a[n+10];
        int x=n/2,q[4]={0};
        ans=0;
        for (int j=1;j<=n;j++){
            cin>>a[j].aa[1]>>a[j].aa[2]>>a[j].aa[3];
            a[j].m[1]=1,a[j].m[2]=2,a[j].m[3]=3;
            int q=a[j].aa[1];
            for (int k=2;k<=3;k++){
                if (a[j].aa[k]>q){
                    q=a[j].aa[k];
                    a[j].m[1]=k;
                }
            }
            a[j].b[1]=a[j].aa[a[j].m[1]];
            q=a[j].aa[1];
            for (int k=2;k<=3;k++){
                if (a[j].aa[k]<q){
                    q=a[j].aa[k];
                    a[j].m[3]=k;
                }
            }
            a[j].b[3]=a[j].aa[a[j].m[3]];
            a[j].m[2]=6-a[j].m[3]-a[j].m[1];
            a[j].b[2]=a[j].aa[a[j].m[2]];
        }
        sort(a+1,a+n+1,cmp1);
        /*for (int j=1;j<=n;j++){
            cout<<a[j].m[1]<<" "<<a[j].m[2]<<" "<<a[j].m[3]<<" "<<a[j].b[1]<<" "<<a[j].b[2]<<" "<<a[j].b[3]<<endl;
        }*/
        for (int j=1;j<=n;j++){
            if (q[a[j].m[1]]<x){
                q[a[j].m[1]]++;
                ans+=a[j].b[1];
                //cout<<"1 "<<q[a[j].m[1]]<<endl;
            }
            else if (q[a[j].m[2]]<x){
                q[a[j].m[2]]++;
                ans+=a[j].b[2];
                //cout<<"2 "<<q[a[j].m[2]]<<endl;
            }
            else {
                q[a[j].m[3]]++;
                ans+=a[j].b[3];
                //cout<<"3 "<<q[a[j].m[3]]<<endl;
            }
        }
        cout<<ans<<endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
