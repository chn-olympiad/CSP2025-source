#include<bits/stdc++.h>
using namespace std;
int n,q,w,e,ans,b[100005][4];
struct node{
    int l1,l2,l3,q;
}a[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        q=0,w=0,e=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>b[i][1]>>b[i][2]>>b[i][3];
            int mx=max({b[i][1],b[i][2],b[i][3]}),mn=min({b[i][1],b[i][2],b[i][3]});
            a[i].l1=b[i][1]-mx;
            a[i].l2=b[i][2]-mx;
            a[i].l3=b[i][3]-mx;
            a[i].q=(a[i].l1==0?1:(a[i].l2==0?2:3));
            if(a[i].q==1)q++;
            if(a[i].q==2)w++;
            if(a[i].q==3)e++;
            /*if(b[i][1]==mx){
                a[i].l1=1;q++;
                if(b[i][2]==mn)a[i].l3=2,a[i].l2=3;
                else a[i].l3=3,a[i].l2=2;
            }
            else{
                if(b[i][2]==mx){
                    a[i].l1=2;w++;
                    if(b[i][1]==mn)a[i].l3=1,a[i].l2=3;
                    else a[i].l3=3,a[i].l2=1;
                }
                else{
                    a[i].l1=3;e++;
                    if(b[i][2]==mn)a[i].l3=2,a[i].l2=1;
                    else a[i].l3=1,a[i].l2=2;

                }
            }*/
            ans+=mx;

        }
        while(q>n/2){
            int mx=-0x7f7f7f7f,z;
            for(int i=1;i<=n;i++)
                if(a[i].q==1&&max(a[i].l2,a[i].l3)>mx)z=i,mx=max(a[i].l2,a[i].l3);
            a[z].q=2;ans+=mx;q--;
        }

        while(w>n/2){
            int mx=-0x7f7f7f7f,z;
            for(int i=1;i<=n;i++)
                if(a[i].q==2&&max(a[i].l1,a[i].l3)>mx)z=i,mx=max(a[i].l1,a[i].l3);
            a[z].q=3;ans+=mx;w--;
        }
        while(e>n/2){
            int mx=-0x7f7f7f7f,z;
            for(int i=1;i<=n;i++)
                if(a[i].q==3&&max(a[i].l2,a[i].l1)>mx)z=i,mx=max(a[i].l2,a[i].l1);
            a[z].q=2;ans+=mx;e--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
