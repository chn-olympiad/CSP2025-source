#include <bits/stdc++.h>

using namespace std;
struct node{
    int id;
    int dis;
}a[1000];
bool cmp(node a,node b){
    return a.dis>b.dis;
}
int main()
{
    int n,m;
    cin>>n>>m;
    freopen("seat","r",stdin);
    freopen<"seat","w",stdout);
    for(int i=1;i<=n*m;i++){
        cin>>a[i].dis;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
       cout<<a[i].dis<<' '<<a[i].id<<endl;
    }
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            if(((i-1)/n+1)%2!=0){
                cout<<(i-1)/n+1<<' '<<(i-1)%n+1;
            }else{
                cout<<(i-1)/n+1<<' '<<n-((i-1)%n);
            }
            break;
        }
    }
    return 0;
}
