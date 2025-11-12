#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int T,n;
struct T{
    int x;
    int y;
    int z;
    int id;
}a[N];
struct Q{
    int num;
    int id;
}b[N],c[N],d[N];
bool cmp(Q x,Q y){
    return x.num>y.num;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].id=i;
        }
        long long ans=0;
        int siz=0,siz2=0,siz3=0;
        for(int i=1;i<=n;i++){
            if(a[i].x>=max(a[i].y,a[i].z)){
                ++siz;
                ans=ans+(long long)a[i].x;
                b[siz].num=-a[i].x+max(a[i].y,a[i].z);
                b[siz].id=a[i].id;
            }
            else if(a[i].y>=max(a[i].x,a[i].z)){
                ++siz2;
                ans=ans+(long long)a[i].y;
                c[siz2].num=-a[i].y+max(a[i].x,a[i].z);
                c[siz2].id=a[i].id;
            }
            else if(a[i].z>=max(a[i].y,a[i].x)){
                ++siz3;
                ans=ans+(long long)a[i].z;
                d[siz3].num=-a[i].z+max(a[i].y,a[i].x);
                d[siz3].id=a[i].id;
            }
        }
        if(siz>=n/2){
            sort(b+1,b+siz+1,cmp);
            for(int i=1;i<=siz-n/2;i++){
                ans=ans+b[i].num;
            }
        }
        else if(siz2>=n/2){
            sort(c+1,c+siz2+1,cmp);
            for(int i=1;i<=siz2-n/2;i++){
                ans=ans+c[i].num;
            }
        }
        else if(siz3>=n/2){
            sort(d+1,d+siz3+1,cmp);
            for(int i=1;i<=siz3-n/2;i++){
                ans=ans+d[i].num;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
