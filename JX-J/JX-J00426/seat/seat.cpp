#include<bits/stdc++.h>
using namespace std;
int p[105],u;
int find(int l,int r)
{
    int mid=(l+r)/2;
    if(l<r){
        if(u>p[mid]){
            return find(l,mid-1);
        }
        else if(u<p[mid]){
            return find(mid,r);
        }
        else return mid;
    }
    return r;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        int a;
        scanf("%d",&a);
        p[i]=a;
    }
    u=p[1];
    sort(p+1,p+1+n*m,greater<int>());
    int t=find(1,n*m);
    int x=t/n+1,y;
    if(t%n==0)x-=1;
    if(x%2==1){
        if(t/n>=1&&t!=n)y=t%n;
        else y=t;
    }
    else y=n-((t-1)%n);
    cout<<x<<' '<<y;
    return 0;

}
