#include<bits/stdc++.h>
using namespace std;
int t;
int n,A,B,C;
struct Int{
    int x,id;
}a[1000010],b[1000010],c[1000010];
bool cmp(Int a,Int b){
    return a.x>b.x;
}
long long ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        A=1;
        B=1;
        C=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i].x=x,a[i].id=i;
            b[i].x=y,b[i].id=i;
            c[i].x=z,c[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        if(a[1].id==b[1].id&&b[1].id==c[1].id){
            if(max(a[1].x,max(b[1].x,c[1].x))==a[1].x)a[1].x=0;
            else if(max(a[1].x,max(b[1].x,c[1].x))==b[1].x)b[1].x=0;
            else if(max(a[1].x,max(b[1].x,c[1].x))==c[1].x)c[1].x=0;
        }
        if(n==2){
            int ans1=-114514,ans2=-114514;
            for(int i=1;i<=n;i++){
                if(a[i].id==1){
                    ans1=max(ans1,a[i].x);
                }
                if(b[i].id==1){
                   ans1=max(ans1,b[i].x);
                }
                if(c[i].id==1){
                    ans1=max(ans1,c[i].x);
                }
                if(a[i].id==2){
                    ans2=max(ans2,a[i].x);
                }
                if(b[i].id==2){
                   ans2=max(ans2,b[i].x);
                }
                if(c[i].id==2){
                    ans2=max(ans2,c[i].x);
                }
            }
            cout<<ans1+ans2<<endl;
        }
        else{
        int N=n-3;
        ans=a[1].x+b[1].x+c[1].x;
        for(int i=2;i<=n;i++){
                if(N==0)break;
                if(max(a[i].x,max(b[i].x,c[i].x))==a[i].x&&A<n/2){
                    ans+=a[i].x;
                    A++;
                }
                else if(max(a[i].x,max(b[i].x,c[i].x))==b[i].x&&B<n/2){
                    ans+=b[i].x;
                    B++;
                }
                else if(max(a[i].x,max(b[i].x,c[i].x))==c[i].x&&C<n/2){
                    ans+=c[i].x;
                    C++;
                }
            N--;
        }
        cout<<ans<<endl;
        }
    }
    return 0;
}
