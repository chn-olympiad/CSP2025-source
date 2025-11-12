#include<bits/stdc++.h>
using namespace std;
long long k=0,n,m,p,a[10001];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    p=n*m;
    for(int i=1;i<=p;i++) cin>>a[i];
    k=a[1];
    sort(a+1,a+p+1,cmp);
    for(int i=1;i<=p;i++) if(a[i]==k){
    int x=i/n,y=i%n;
    x+=1;
    if(y==0){
        x--;
        y=n;
    }
    cout<<x<<' '<<y;
    fclose(stdin);
    fclose(stdout);
    return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

