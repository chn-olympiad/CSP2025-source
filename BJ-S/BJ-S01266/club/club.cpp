#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long T;
long long n;
struct Node{
    long long s1;
    long long s2;
    long long s3;
}p[N];
long long a1[N];
long long a2[N];
long long a3[N];
long long cnt1;
long long cnt2;
long long cnt3;
long long ans1;
void devide(long long u){
    if(p[u].s1>=p[u].s2&&p[u].s1>=p[u].s3){
        a1[++cnt1]=u;
        ans1+=p[u].s1;
    }
    else if(p[u].s2>=p[u].s1&&p[u].s2>=p[u].s3){
        a2[++cnt2]=u;
        ans1+=p[u].s2;
    }
    else{
        a3[++cnt3]=u;
        ans1+=p[u].s3;
    }
}
bool cmp1(long long x,long long y){
    return min((p[x].s1-p[x].s2),(p[x].s1-p[x].s3))<min((p[y].s1-p[y].s2),(p[y].s1-p[y].s3));
}
bool cmp2(long long x,long long y){
    return min((p[x].s2-p[x].s1),(p[x].s2-p[x].s3))<min((p[y].s2-p[y].s1),(p[y].s2-p[y].s3));
}
bool cmp3(long long x,long long y){
    return min((p[x].s3-p[x].s2),(p[x].s3-p[x].s1))<min((p[y].s3-p[y].s2),(p[y].s3-p[y].s1));
}
int main(){

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cnt1=cnt2=cnt3=0;
        cin>>n;
        ans1=0;
        for(int i=1;i<=n;i++){
            cin>>p[i].s1>>p[i].s2>>p[i].s3;
            devide(i);
        }
        long long size_=n/2;
        if(cnt1>size_){
            sort(a1+1,a1+1+cnt1,cmp1);
            long long q=cnt1-size_;
            for(int i=1;i<=q;i++){
                ans1-=min(p[a1[i]].s1-p[a1[i]].s2,p[a1[i]].s1-p[a1[i]].s3);
            }
            long long ans=ans1;
            cout<<ans<<endl;
        }
        else if(cnt2>size_){
            sort(a2+1,a2+1+cnt2,cmp2);
            long long q=cnt2-size_;
            for(int i=1;i<=q;i++){
                ans1-=min(p[a2[i]].s2-p[a2[i]].s1,p[a2[i]].s2-p[a2[i]].s3);
            }
            long long ans=ans1;
            cout<<ans<<endl;
        }
        else if(cnt3>size_){
            sort(a3+1,a3+1+cnt3,cmp3);
            long long q=cnt3-size_;
            for(int i=1;i<=q;i++){
                ans1-=min(p[a3[i]].s3-p[a3[i]].s1,p[a3[i]].s3-p[a3[i]].s2);
            }
            long long ans=ans1;
            cout<<ans<<endl;
        }
        else{
            long long ans=ans1;
            cout<<ans<<endl;
        }
    }


    return 0;

}
