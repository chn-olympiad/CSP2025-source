#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,t;
struct stu{
    int x,y,z;
    int num,chu;
}a[100005];
bool cmp(int a,int b){
    return a>b;
}
bool cmpp(stu a,stu b){
    return a.chu<b.chu;
}
int cha(int a,int b,int c){
    int x[4];
    x[1]=a,x[2]=b,x[3]=c;
    sort(x+1,x+4,cmp);
    return x[1]-x[2];
}
ll sum[5],ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        ans=0;
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            cin >> a[i].x >> a[i].y >> a[i].z;
            ans+=max(max(a[i].x,a[i].y),a[i].z);
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
                a[i].num=1;
            }
            else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
                a[i].num=2;
            }
            else a[i].num=3;
            a[i].chu=cha(a[i].x,a[i].y,a[i].z);
            sum[a[i].num]++;
        }
        sort(a+1,a+n+1,cmpp);
        if(sum[1]>(n/2)){
            int gg=(sum[1]-(n/2));
            for(int i=1;i<=n;i++){
                if(a[i].num==1){
                    ans-=a[i].chu;
                    gg--;
                }
                if(gg==0) break;
            }
        }
        if(sum[2]>(n/2)){
            int gg=(sum[2]-(n/2));
            for(int i=1;i<=n;i++){
                if(a[i].num==2){
                    ans-=a[i].chu;
                    gg--;
                }
                if(gg==0) break;
            }
        }
        if(sum[3]>(n/2)){
            int gg=(sum[3]-(n/2));
            for(int i=1;i<=n;i++){
                if(a[i].num==3){
                    ans-=a[i].chu;
                    gg--;
                }
                if(gg==0) break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
