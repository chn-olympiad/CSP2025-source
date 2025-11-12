#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int t;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1;
    int ans;
    for(int i=1;i<=n*m;i++){
        if(t==a[i]){
            ans=i;
            break;
        }
    }
    int c=1;
    while(c<ans){
        while(x<n&&c<ans){
            x++;
            c++;
        }
        if(c>=ans){
            break;
        }
        y++;
        c++;
        if(c>=ans){
            break;
        }
        while(x>1&&c<ans){
            x--;
            c++;
        }
        if(c>=ans){
            break;
        }
        y++;
        c++;
    }
    cout<<y<<' '<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
