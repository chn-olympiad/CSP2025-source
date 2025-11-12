#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int a1,a2,a3;
    int f(){
        if(a1>a2&&a1>a3)return 1;
        if(a2>a1&&a2>a3)return 2;
        return 3;
    }
}a[100005];
bool cmp(node x,node y){
    if(x.f()==1&&y.f()!=1)return 1;
    if(x.f()!=1&&y.f()==1)return 0;
    return min(x.a1-x.a2,x.a1-x.a3)<min(y.a1-y.a2,y.a1-y.a3);
}
bool cmp2(node x,node y){
    if(x.f()==2&&y.f()!=2)return 1;
    if(x.f()!=2&&y.f()==2)return 0;
    return min(x.a2-x.a1,x.a2-x.a3)<min(y.a2-y.a1,y.a2-y.a3);
}
bool cmp3(node x,node y){
    if(x.f()==3&&y.f()!=3)return 1;
    if(x.f()!=3&&y.f()==3)return 0;
    return min(x.a3-x.a1,x.a3-x.a2)<min(y.a3-y.a1,y.a3-y.a2);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int cnt[4]={0},ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            cnt[a[i].f()]++;
            ans+=max({a[i].a1,a[i].a2,a[i].a3});
        }
        if(cnt[1]>n/2){
            sort(a+1,a+1+n,cmp);
            int tmp=cnt[1]-n/2;
            for(int j=1;j<=tmp;j++){
                if(a[j].a2>a[j].a3){
                    if(cnt[2]<n/2){
                        cnt[1]--;
                        cnt[2]++;
                        ans=ans-a[j].a1+a[j].a2;
                    }else{
                        cnt[1]--;
                        cnt[3]++;
                        ans=ans-a[j].a1+a[j].a3;
                    }
                }else{
                    if(cnt[3]<n/2){
                        cnt[1]--;
                        cnt[3]++;
                        ans=ans-a[j].a1+a[j].a3;
                    }else{
                        cnt[1]--;
                        cnt[2]++;
                        ans=ans-a[j].a1+a[j].a2;
                    }
                }
            }
        }
        else if(cnt[2]>n/2){
            sort(a+1,a+1+n,cmp2);
            int tmp=cnt[2]-n/2;
            for(int j=1;j<=tmp;j++){
                if(a[j].a1>a[j].a3){
                    if(cnt[1]<n/2){
                        cnt[2]--;
                        cnt[1]++;
                        ans=ans-a[j].a2+a[j].a1;
                    }else{
                        cnt[2]--;
                        cnt[3]++;
                        ans=ans-a[j].a2+a[j].a3;
                    }
                }else{
                    if(cnt[3]<n/2){
                        cnt[2]--;
                        cnt[3]++;
                        ans=ans-a[j].a2+a[j].a3;
                    }else{
                        cnt[2]--;
                        cnt[1]++;
                        ans=ans-a[j].a2+a[j].a1;
                    }
                }
            }
        }
        else if(cnt[3]>n/2){
            sort(a+1,a+1+n,cmp3);
            int tmp=cnt[3]-n/2;
            for(int j=1;j<=tmp;j++){
                if(a[j].a1>a[j].a2){
                    if(cnt[1]<n/2){
                        cnt[3]--;
                        cnt[1]++;
                        ans=ans-a[j].a3+a[j].a1;
                    }else{
                        cnt[3]--;
                        cnt[2]++;
                        ans=ans-a[j].a3+a[j].a2;
                    }
                }else{
                    if(cnt[2]<n/2){
                        cnt[3]--;
                        cnt[2]++;
                        ans=ans-a[j].a3+a[j].a2;
                    }else{
                        cnt[3]--;
                        cnt[1]++;
                        ans=ans-a[j].a3+a[j].a1;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
