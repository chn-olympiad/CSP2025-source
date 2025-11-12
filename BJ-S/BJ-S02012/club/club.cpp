#include<bits/stdc++.h>
using namespace std;
int t,n;
struct num{
    int t[4];
    int b1,b2,b3;
    int maxn;
    bool flag=true;
}a[100001],cntn1[100001],cntn2[100001],cntn3[100001];
bool cmp(num a,num b){
    return a.maxn>b.maxn;
}
long long ans;
bool cmp1(num c,num d){
    if(c.t[c.b2]>d.maxn){
        return true;
    }else if(c.maxn<d.t[d.b2]){
        return false;
    }else{
        return c.maxn<d.maxn;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        for(int i=1;i<=n;i++){
            a[i].maxn=cntn1[i].maxn=cntn2[i].maxn=cntn3[i].maxn=0;
            a[i].b1=cntn1[i].b1=cntn2[i].b1=cntn3[i].b1=0;
            a[i].b2=cntn1[i].b2=cntn2[i].b2=cntn3[i].b2=0;
            a[i].b3=cntn1[i].b3=cntn2[i].b3=cntn3[i].b3=0;
            for(int i=1;i<=3;i++){
                a[i].t[i]=cntn1[i].t[i]=cntn2[i].t[i]=cntn3[i].t[i]=0;
            }
        }
        int cnt=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i].t[1]>>a[i].t[2]>>a[i].t[3];
            for(int j=1;j<=3;j++){
                if(a[i].t[j]>a[i].maxn){
                    a[i].maxn=a[i].t[j];
                    a[i].b3=a[i].b2;
                    a[i].b2=a[i].b1;
                    a[i].b1=j;
                }else if(a[i].t[j]>a[i].t[a[i].b2]){
                    a[i].b3=a[i].b2;
                    a[i].b2=j;
                }else{
                    a[i].b3=j;
                }
            }
        }
        sort(a+1,a+1+n,cmp);
        ans=0;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            if(a[i].b1==1){
                cnt1++;
                cntn1[cnt1]=a[i];
                ans+=a[i].maxn;
            }else if(a[i].b1==2){
                cnt2++;
                cntn2[cnt2]=a[i];
                ans+=a[i].maxn;
            }else{
                cnt3++;
                cntn3[cnt3]=a[i];
                ans+=a[i].maxn;
            }
        }
        if(cnt1>cnt){
           sort(cntn1+1,cntn1+cnt1+1,cmp1);
           for(int i=1;i<=cnt1-cnt;i++){
                ans-=cntn1[i].maxn;
                ans+=cntn1[i].t[cntn1[i].b2];
                cout<<cntn1[i].maxn<<endl<<cntn1[i].t[cntn1[i].b2];
          }
        }
        if(cnt2>cnt){
           sort(cntn2+1,cntn2+cnt2+1,cmp1);
           for(int i=1;i<=cnt2-cnt;i++){
                ans-=cntn2[i].maxn;
                ans+=cntn2[i].t[cntn2[i].b2];

           }
        }
        if(cnt3>cnt){
           sort(cntn3+1,cntn3+cnt3+1,cmp1);
           for(int i=1;i<=cnt3-cnt;i++){
                ans-=cntn3[i].maxn;
                ans+=cntn3[i].t[cntn3[i].b2];
           }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

