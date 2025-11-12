#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct md{
    int a,b,c;
}cnt;
int t,n,a[N],b[N],c[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        cnt.a=cnt.b=cnt.c=0;
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        int mid=n/2,f=0;
        for(int i=1;i<=n;i++){
            int mx=0;
            mx=max(a[i],max(b[i],c[i]));
            if(mx==a[i]&&cnt.a+1<=mid){
                f+=a[i];
                cnt.a++;
            }else if(mx==b[i]&&cnt.b+1<=mid){
                f+=b[i];
                cnt.b++;
            }else if(mx==c[i]&&cnt.c+1<=mid){
                f+=c[i];
                cnt.c++;
            }else if(mx==a[i]&&cnt.a+1>mid){
                if(b[i]>c[i]&&cnt.b+1<=mid){
                    f+=b[i];
                    cnt.b++;
                }else{
                    if(cnt.c+1<=mid){
                        f+=c[i];
                        cnt.c++;
                    }
                }
            }else if(mx==b[i]&&cnt.b+1>mid){
                if(a[i]>c[i]&&cnt.a+1<=mid){
                    f+=a[i];
                    cnt.a++;
                }else{
                    if(cnt.c+1<=mid){
                        f+=c[i];
                        cnt.c++;
                    }
                }
            }else if(mx==c[i]&&cnt.c+1>mid){
                if(b[i]>a[i]&&cnt.b+1<=mid){
                    f+=b[i];
                    cnt.b++;
                }else{
                    if(cnt.a+1<=mid){
                        f+=a[i];
                        cnt.a++;
                    }
                }
            }
        }
        cout<<f<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
