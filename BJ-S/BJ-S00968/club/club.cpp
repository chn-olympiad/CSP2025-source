#include<bits/stdc++.h>
using namespace std;
long long n,a[100004][4];
int dg(int o,int b,int c,int h,int s){
    if(h==n){
        return s;
    }
    int maxx=-1;
    if(o<=n/2){
        s+=a[h][1];
        maxx=max(maxx,dg(o+1,b,c,h+1,s));
        s-=a[h][1];
    }
    if(b<=n/2){
        s+=a[h][2];
        maxx=max(maxx,dg(o,b+1,c,h+1,s));
        s-=a[h][2];
    }
    if(c<=n/2){
        s+=a[h][3];
        maxx=max(maxx,dg(o,b,c+1,h+1,s));
        s-=a[h][3];
    }
    return maxx;
}
void solve1(){
    int b[100005];
    for(int i=0;i<n;i++){
        b[i]=a[i][1];
    }
    sort(b,b+n);
    int y=n-1,sum=0;
    while(y>=n/2){
        sum+=b[y];
        y--;
    }
    cout<<sum;
    return ;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","out",stdout);
    int t;
    bool flag1;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0 || a[i][3]!=0){
                flag1=1;
            }
        }
        if(flag1==0){
            solve1();
            return 0;
        }
        cout<<dg(0,0,0,0,0)<<endl;
    }
    return 0;
}
