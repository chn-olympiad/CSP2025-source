#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
bool cmp(int a,int b){
    return a>b;
}
struct stu{
    int x;
    int id;
    int y;
}d[1005];
bool cmp1(stu a,stu b){
    return a.x>b.x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int x[205];
    int ans;
    while(t--){
        int n;
        cin>>n;
        int bx=1,cx=1;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0){
                bx=0;
            }
            if(c[i]!=0){
                cx=0;
            }
        }
        if(bx==1&&cx==1){
            sort(a+1,a+n+1,cmp);
            ans=0;
            for(int i=1;i<=n/2;i++){
                ans+=a[i];
            }
            cout<<ans<<endl;
        }else if(cx==1&&bx!=1){
            for(int i=1;i<=n;i++){
                d[i].x=max(a[i],b[i]);
                if(d[i].x==a[i]&&d[i].x!=b[i]){
                    d[i].id=1;
                    d[i].y=b[i];
                }else if(d[i].x!=a[i]&&d[i].x==b[i]){
                    d[i].id=2;
                    d[i].y=a[i];
                }else{
                    d[i].id=0;
                }
            }
            int ans3=0;
            sort(d+1,d+n+1,cmp1);
            int e1=0,e2=0;
            for(int i=1;i<=n;i++){
                    if(d[i].id==1&&e1<n/2){
                        e1++;
                        ans3+=d[i].x;
                    }else if(e2<n/2){
                        e2++;
                        ans3+=d[i].x;
                    }else{
                    ans3+=d[i].y;
                }
            }
            cout<<ans3<<endl;
        }else if(n==2){
            int ans1=max(a[1]+b[2],max(a[1]+c[2],max(b[1]+c[2],max(a[2]+b[1],max(a[2]+c[1],b[2]+c[1])))));
            cout<<ans1<<endl;
        }else{
            int ans2=0;
                for(int i=1;i<=n;i++){
                    ans2+=max(a[i],max(b[i],c[i]));
                }
                cout<<ans2<<endl;
            }
        }
    return 0;
}
