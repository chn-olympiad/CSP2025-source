#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+16;
struct node{
    int d;
    long long num;
    int id;
};
bool cmp(node a,node b){
    if(a.d==b.d){
        return a.num>b.num;
    }
    return a.d>b.d;
}
node o;
int n,t;
int a[MAXN],b[MAXN],c[MAXN];
node d1[MAXN],d2[MAXN],d3[MAXN];
bool used[MAXN];
long long ans;
/*void dfs(int i,int sum1,int sum2,int sum3,long long cnt){
    if(sum1>n/2||sum2>n/2||sum3>n/2){
        return;
    }
    if(i==n){
        ans=max(ans,cnt);
    }
    dfs(i+1,sum1+1,sum2,sum3,cnt+a[i+1]);
    dfs(i+1,sum1,sum2+1,sum3,cnt+b[i+1]);
    dfs(i+1,sum1,sum2,sum3+1,cnt+c[i+1]);
}*/
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        memset(used,0,sizeof(used));
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            o.num=a[i];
            o.d=min(a[i]-b[i],a[i]-c[i]);
            o.id=i;
            d1[i]=o;
            o.num=b[i];
            o.d=min(b[i]-a[i],b[i]-c[i]);
            d2[i]=o;
            o.num=c[i];
            o.d=min(c[i]-b[i],c[i]-a[i]);
            d3[i]=o;
        }
        sort(d1+1,d1+1+n,cmp);
        /*for(int i=1;i<=n;i++){
            cout<<d1[i].id<<" ";
        }
        cout<<endl;*/
        sort(d2+1,d2+1+n,cmp);
        /*for(int i=1;i<=n;i++){
            cout<<d2[i].id<<" ";
        }
        cout<<endl;*/
        sort(d3+1,d3+1+n,cmp);
        /*for(int i=1;i<=n;i++){
            cout<<d3[i].id<<" ";
        }
        cout<<endl;*/
        for(int i=1,j=1,k=1,cnt1=0,cnt2=0,cnt3=0;cnt1+cnt2+cnt3<=n;){
            while(used[d1[i].id]){
                i++;
                //cout<<"-1"<<endl;
            }
            while(used[d2[j].id]){
                j++;
                //cout<<"-1"<<endl;
            }
            while(used[d3[k].id]){
                k++;
                //cout<<"-1"<<endl;
            }
            if(cnt1>=n/2&&d1[i].d>=0){
                if(d2[j].d>d3[k].d){
                    ans+=d2[j].num;
                    used[d2[j].id]=1;
                    j++;
                    cnt2++;
                }
                else{
                    ans+=d3[k].num;
                    used[d3[k].id]=1;
                    k++;
                    cnt3++;
                }
                //cout<<"-2"<<endl;
            }
            else if(cnt2>=n/2&&d2[j].d>=0){
                if(d1[i].d>d3[k].d){
                    ans+=d1[i].num;
                    used[d1[i].id]=1;
                    i++;
                    cnt1++;
                }
                else{
                    ans+=d3[k].num;
                    used[d3[k].id]=1;
                    k++;
                    cnt3++;
                }
                //cout<<"-3"<<endl;
            }
            else if(cnt3>=n/2&&d3[k].d>=0){
                if(d2[j].d>d1[i].d){
                    ans+=d2[j].num;
                    used[d2[j].id]=1;
                    j++;
                    cnt2++;
                }
                else{
                    ans+=d1[i].num;
                    used[d1[i].id]=1;
                    i++;
                    cnt1++;
                }
                //cout<<"-4"<<endl;
            }
            while(d1[i].d>=0&&cnt1<n/2&&cnt1+cnt2+cnt3<=n&&!used[d1[i].id]){
                ans+=d1[i].num;
                used[d1[i].id]=1;
                i++;
                cnt1++;
                //cout<<"aaa"<<endl;
            }
            while(d2[j].d>=0&&cnt2<n/2&&cnt1+cnt2+cnt3<=n&&!used[d2[j].id]){
                //cout<<"bbb";
                ans+=d2[j].num;
                used[d2[j].id]=1;
                j++;
                cnt2++;
                //cout<<"bbb"<<endl;
            }
            while(d3[k].d>=0&&cnt3<n/2&&cnt1+cnt2+cnt3<=n&&!used[d3[k].id]){
                ans+=d3[k].num;
                used[d3[k].id]=1;
                k++;
                cnt3++;
                //cout<<"ccc"<<endl;
            }
            // cout<<i<<" "<<j<<" "<<k<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
