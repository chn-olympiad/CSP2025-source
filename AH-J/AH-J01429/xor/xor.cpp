#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500005];
struct stu{
    int l,r;
    bool f;
}b[500005];
bool cmp(stu x,stu y){
    if(x.r!=y.r){
        return x.r<y.r;
    }
    return x.l>y.l;
}
bool check(int i,int j){
    bool f1,f2,f3,f4;
    f1=b[i].l>=b[j].l&&b[i].r<=b[j].r;//当前区间右端点在主区间内
    f3=b[i].l<=b[j].l&&b[i].r<=b[j].r;//当前区间包括了主区间
    return f1||f3;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int sum=a[i];
        int j=i;
        while(j<=n){
            if(sum==k){
                b[++cnt].l=i;
                b[cnt].r=j;
            }
            j++;
            sum=sum^a[j];
        }
    }
    sort(b+1,b+cnt+1,cmp);
    int ans=0;
    for(int i=1;i<=cnt;i++){
        if(b[i].f==0){
            ans++;
            int j=i+1;
            while(check(i,j)&&j<=n){
                b[j].f=1;
                j++;
            }
        }
        //cout<<b[i].l<<' '<<b[i].r<<' '<<b[i].f<<' '<<ans<<endl;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
