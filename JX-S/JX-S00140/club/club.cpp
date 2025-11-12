#include<bits/stdc++.h>
using namespace std;
int n,t,ans,x,y,z,ma,man,maxn,k;
struct node{
    int sum;
    int hp;
};
node a[100005],b[100005],c[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].sum>>b[i].sum>>c[i].sum;
        }
        for(int i=1;i<=n;i++){
            if(ma<a[i].sum)  ma=a[i].sum;
            if(man<b[i].sum)  man=b[i].sum;
            if(maxn<c[i].sum)  maxn=c[i].sum;
        }
        for(int i=1;i<=n;i++){
            if(a[i].sum==ma&&x<n/2){
                x++;
                ans+=a[i].sum;
                a[i].hp++;
            }
            if(b[i].sum==man&&y<n/2){
                y++;
                ans+=b[i].sum;
                b[i].hp++;
            }
            if(c[i].sum==maxn&&z<n/2){
                z++;
                ans+=c[i].sum;
                c[i].hp++;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i].hp!=0&&b[i].hp!=0){
                if(c[i].hp!=0||z<n/2){
                    k=max(a[i].sum,max(b[i].sum,c[i].sum));
                    if(k==a[i].sum){
                        ans+=k;
                        x++;
                    }
                    else if(k==b[i].sum){
                        ans+=k;
                        y++;
                    }
                    else if(k==c[i].sum){
                        ans+=k;
                        z++;
                    }
                }
                else{
                    k=max(a[i].sum,b[i].sum);
                    ans+=k;
                    if(k==a[i].sum)  x++;
                    else if(k==b[i].sum)  y++;
                }
            }
            else if(a[i].hp!=0&&c[i].hp!=0){
                if(b[i].hp!=0||y<n/2){
                    k=max(a[i].sum,max(b[i].sum,c[i].sum));
                    if(k==a[i].sum){
                        ans+=k;
                        x++;
                    }
                    else if(k==b[i].sum){
                        ans+=k;
                        y++;
                    }
                    else if(k==c[i].sum){
                        ans+=k;
                        z++;
                    }
                }
                else{
                    k=max(a[i].sum,c[i].sum);
                    ans+=k;
                    if(k==a[i].sum)  x++;
                    else if(k==c[i].sum)  z++;
                }
            }
            else if(b[i].hp!=0&&c[i].hp!=0){
                if(a[i].hp!=0||x<n/2){
                    k=max(a[i].sum,max(b[i].sum,c[i].sum));
                    if(k==a[i].sum){
                        ans+=k;
                        x++;
                    }
                    else if(k==b[i].sum){
                        ans+=k;
                        y++;
                    }
                    else if(k==c[i].sum){
                        ans+=k;
                        z++;
                    }
                }
                else{
                    k=max(c[i].sum,b[i].sum);
                    ans+=k;
                    if(k==c[i].sum)  z++;
                    else if(k==b[i].sum)  y++;
                }
            }
        }
        cout<<ans<<endl;
        ans=0;
        ma=0;
        man=0;
        maxn=0;
        x=0;
        y=0;
        z=0;
        for(int i=1;i<=n;i++){
            a[i].hp=0;
            b[i].hp=0;
            c[i].hp=0;
        }
    }
    return 0;
}
