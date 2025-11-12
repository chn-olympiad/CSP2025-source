#include<iostream>

using namespace std;

const int N=5*1e5+10;

int n,k;
int a[N];
int ans=0;
int y[N];

void d(int x){

}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    if(n<=2&&k==0){
        if(n==1){
            int x;
            cin>>x;
            if(x==0)
                ans++;
        }
        if(n==2){
            int x,y;
            cin>>x>>y;
            if(x==1&&y==1)
                ans=1;
            if(x==0)
                ans++;
            if(y==0)
                ans++;
        }
        printf("%d",ans);
        return 0;
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(a[n]==k)
        ans=1,y[n]=1;
    d(n-1);

    printf("%d",ans);

    return 0;
}
